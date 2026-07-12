//#include "script_component.hpp"

if (mjb_disableStackMove) exitWith { systemChat "Stack moving is disabled."; };



if !(canSuspend) exitWith { _this spawn bettinv_main_fnc_StackMove; };

private _cooldown = mjb_stackMoveCooldown;
if (_cooldown > 0 && {!isNil 'mjb_bettinvStackCD' }) exitWith { systemChat "Stack moving is on cooldown."; };

// Prepare Script
params ["_item","_source","_target","_size"];
private ["_bettinv_old_magazinesList","_sourceContainer", "_targetContainer","_itemType"];

if (_cooldown > 0) then {
	systemChat str [_size,(_cooldown * (_size / 5))];
	mjb_bettinvStackCD = true;
	[{ mjb_bettinvStackCD = nil; },[],(_cooldown * (_size / 5))] call CBA_fnc_waitAndExecute;
};

private _limit = mjb_stackLimit;
if ( _size > _limit ) then { _size = _limit; };

_size = _size - 1;
if (_item == "") exitWith {}; // if Item is empty something is wrong, so Exit
if (isText(configFile >> "CfgWeapons" >> _item >> "ItemInfo" >> "containerClass")) exitWith {}; // Exit if Uniform/Vest

// Check for right containers
bettinv_player_container_load_new = [] call bettinv_main_fnc_get_player_container_load;
if (isPlayer _source) then {
	{
		if (_x select 1 > (bettinv_player_container_load_new select _forEachIndex) select 1) exitWith {
			_sourceContainer = _x select 0;
			if (count (bettinv_old_magazines select _forEachIndex) != 0) then {
				_bettinv_old_magazinesList = +(bettinv_old_magazines select _forEachIndex);
			} else {
				_bettinv_old_magazinesList = [];
			};
		};
	} forEach bettinv_player_container_load;
} else {
	_sourceContainer = _source;
};
if (isPlayer _target) then {
	{
		if (_x select 1 < (bettinv_player_container_load_new select _forEachIndex) select 1) exitWith {
			_targetContainer = _x select 0;
			if (count (bettinv_old_magazines select _forEachIndex) != 0) then {
				_bettinv_old_magazinesList = +(bettinv_old_magazines select _forEachIndex);
			} else {
				_bettinv_old_magazinesList = [];
			};
		};
	} forEach bettinv_player_container_load;
} else {
	_targetContainer = _target;
};

// Check if Item or Magazine, and Exit if is neither of those two
if (_item in itemCargo _sourceContainer) then {
	_itemType = "item";
} else {
	if (_item in magazineCargo _sourceContainer) then {
		_itemType = "magazine";
	};
};
if (isNil "_itemType") exitWith {};

// Prepare Variables for Stack Move
_mags = magazinesAmmoCargo _sourceContainer;
_magazine = [];
_itemMagazinesFull = [];
_itemMagazinesUsed = [];
_itemMagazines = [];
_otherMagazines = [];

// Exit when the Item is Magazine and no magazine in Source
if ((_itemType == "magazine") AND (count _mags == 0)) exitWith {};

// Start Magazine Stack Move
if (_itemType == "magazine") then {
	_NewMagList = [];
	// Define New List for Magazines
	if (isPlayer _source) then {
		_NewMagList = magazinesAmmoCargo _sourceContainer;
		{
			if ((count _NewMagList - 1) < _forEachIndex) exitWith {_magazine = +_x};
			if !(_x isEqualTo (_NewMagList select _forEachIndex)) exitWith {_magazine = +_x};
		} forEach _bettinv_old_magazinesList;
	} else {
		_NewMagList = magazinesAmmoCargo _targetContainer;
		{
			if ((count _bettinv_old_magazinesList - 1) < _forEachIndex) exitWith {_magazine = +_x};
			if !(_x isEqualTo (_bettinv_old_magazinesList select _forEachIndex)) exitWith {_magazine = +_x};
		} forEach _NewMagList;
	};

	_magsCount = count _mags - 1;
	for "_i" from 0 to _magsCount do {
		_mag = _mags select _i;
		
		if ((_mag select 0) == _item) then {
			_ItemMagazines append [_mag];
		} else {
			_otherMagazines append [_mag];
		};
	};
	
	// Filter Full Magazines
	_mag_count = getNumber (configFile >> "CfgMagazines" >> _item >> "count");
	{
		if ((_x select 1) == _mag_count) then {
			_itemMagazinesFull append [_itemMagazines select _forEachIndex];
		} else {
			_itemMagazinesUsed append [_itemMagazines select _forEachIndex];
		};
	} forEach _itemMagazines;
	
	// Clear Magazines from Container
	clearMagazineCargoGlobal _sourceContainer;
};
	//diag_log format ["Item:%1,Target:%2,CanAdd:%3",_item,_targetContainer,([_item,"",-1,_targetContainer] call bettinv_main_fnc_canAdd)]; /////////////// _targetContainer can be "any" Bug?
for "_i" from 1 to _size do {
	// End loop if Item has no space in Container or no more Items are available
	if (!([_item,"",-1,_targetContainer] call bettinv_main_fnc_canAdd) OR ((_itemType == "item") AND !(_item in itemCargo _sourceContainer)) OR ((_itemType == "magazine") AND !(count _itemMagazines > 0)) ) exitWith {};

	_fullMag = false;
	if ((_itemType == "magazine") AND (isNil "_magazine")) exitWith {}; // Fix for the moment, should be realy fixed in the future, "_magazine" can be "any" sometimes
	if (_itemType == "magazine") then {
		if (_magazine select 1 == getNumber (configFile >> "CfgMagazines" >> _magazine select 0 >> "count")) then {
			_fullMag = true;
		};
	};
	
	// End loop if mag is full but no other is in cargo ERROR?
	if ((_itemType == "magazine") AND (count _itemMagazinesFull == 0) AND (_fullMag)) exitWith {};
	
	// End loop if mag is used(Not full) but no other is in cargo
	if ((_itemType == "magazine") AND (count _itemMagazinesUsed == 0) AND !(_fullMag)) exitWith {};
	
	if (_itemType == "item") then {
		[_sourceContainer, _item, 1] call CBA_fnc_removeItemCargo;
		[_targetContainer, _item, 1, false] call CBA_fnc_addItemCargo;
	} else {
		if ((_magazine select 1 == getNumber (configFile >> "CfgMagazines" >> _magazine select 0 >> "count")) AND (count _itemMagazinesFull != 0)) then {
			_mag = _itemMagazinesFull select 0;
			[_targetContainer, (_mag select 0),1,false,(_mag select 1)] call CBA_fnc_addMagazineCargo;
			//_targetContainer addMagazineAmmoCargo [(_mag select 0), 1, (_mag select 1)];
			_itemMagazinesFull deleteAt 0;
		} else {
			if ((_magazine select 1 != getNumber (configFile >> "CfgMagazines" >> _magazine select 0 >> "count")) AND (count _itemMagazinesUsed != 0)) then {
				_mag = _itemMagazinesUsed select 0;
				[_targetContainer, (_mag select 0),1,false,(_mag select 1)] call CBA_fnc_addMagazineCargo;
				//_targetContainer addMagazineAmmoCargo [(_mag select 0), 1, (_mag select 1)];
				_itemMagazinesUsed deleteAt 0;
			};
		};
	};
};

// Add back rest of the magazines
if (count _itemMagazinesFull != 0) then {
	{
		_sourceContainer addMagazineAmmoCargo [_x select 0, 1, _x select 1];
	} forEach _itemMagazinesFull;
};
if (count _itemMagazinesUsed != 0) then {
	{
		_sourceContainer addMagazineAmmoCargo [_x select 0, 1, _x select 1];
	} forEach _itemMagazinesUsed;
};
if (count _otherMagazines != 0) then {
	{
		_sourceContainer addMagazineAmmoCargo [_x select 0, 1, _x select 1];
	} forEach _otherMagazines;
};
//systemchat format ["Source:%1,Target:%2,Item:%3,ItemType:%4",_sourceContainer,_targetContainer,_item,_itemType];