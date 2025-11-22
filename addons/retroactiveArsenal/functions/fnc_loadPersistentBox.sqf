params [['_crate',objNull],['_varname','']];

private _loadbox = (missionProfileNamespace getVariable [_varName,nil]);
if (mjb_profCrateOverride) then {_loadbox = (profileNamespace getVariable [_varName,nil]);};
if (!isNil "_loadbox") exitWith {
  clearItemCargoGlobal _crate;
  clearMagazineCargoGlobal _crate;
  clearWeaponCargoGlobal _crate;
  clearBackpackCargoGlobal _crate;

  private _kkohitems = _loadbox # 0;
  private _kkohweaps = _loadbox # 1;
  private _kkohmags = _loadbox # 2;
  private _kkohpacks = _loadbox # 3;
  private _i = 0;
  {
    _crate addItemCargoGlobal [_x, (_kkohitems # 1) # _i];
    _i = _i + 1;
  } forEach _kkohitems # 0;

  _i = 0;
  {
    _crate addWeaponWithAttachmentsCargoGlobal [_x, 1];
    _i = _i + 1;
  } forEach _kkohweaps;

  _i = 0;
  {
    _crate addItemCargoGlobal [_x, (_kkohmags # 1) # _i];
    _i = _i + 1;
  } forEach _kkohmags # 0;

  _i = 0;
  {
    _crate addBackpackCargoGlobal [_x, (_kkohpacks # 1) # _i];
  } forEach _kkohpacks # 0;
};