

/* // switch mags on arsenal close instead, convert back on arsenal open????
  if ("tracer" in _magazine) then {};
  _newMag = [_magazine,"Yellow_Tracer","Red_Tracer"] call CBA_fnc_replace;
  _newMag = [_magazine,"Tracer_Yellow","Tracer_Red"] call CBA_fnc_replace;
  _newMag = [_magazine,"TracerY","TracerR"] call CBA_fnc_replace;
  _newMag = [_magazine,"trc_ylw","trc_red"] call CBA_fnc_replace;
  if (isClass (configFile >> 'CfgMagazines' >> _newMag)) then {};
private _tracer = ["Green","Red","Yellow","","","","","","",""] select _sideID;
if (_tracer isEqualTo "") then {_tracer = "Yellow"};
*/