params [["_box",objNull,[objNull]], "_varName"];
if (_box isEqualTo objNull) exitWith {false};

private _boxitems = getItemCargo _box;
private _boxweaps = weaponsItemsCargo _box;
private _boxmags = getMagazineCargo _box;
private _boxpacks = getBackpackCargo _box;

private _storage = everyContainer _box;
{
    _x = _x # 1;
    private _xitems = getItemCargo _x;
    private _xweaps = weaponsItemsCargo _x;
    private _xmags = getMagazineCargo _x;
    (_boxitems # 0) append (_xitems # 0); (_boxitems # 1) append (_xitems # 1);
    _boxweaps append _xweaps;
    (_boxmags # 0) append (_xmags # 0); (_boxmags # 1) append (_xmags # 1);
} forEach (_storage);

if (mjb_profCrateOverride) exitWith {
  profileNamespace setVariable [_varName, [_boxitems, _boxweaps, _boxmags, _boxpacks]]; saveProfileNamespace;

  private _boxesName = ('mjb_persistentBoxes' + _varName);
  private _boxes = (missionNamespace getVariable [_boxesName,[]]);
  {
    [_x,_varName] call mjb_arsenal_fnc_loadPersistentBox;
  } forEach _boxes - [_box];
};

missionProfileNamespace setVariable [_varName, [_boxitems, _boxweaps, _boxmags, _boxpacks]];
saveMissionProfileNamespace;

private _boxesName = ('mjb_persistentBoxes' + _varName);
private _boxes = (missionNamespace getVariable [_boxesName,[]]);
{
  [_x,_varName] call mjb_arsenal_fnc_loadPersistentBox;
} forEach _boxes - [_box];