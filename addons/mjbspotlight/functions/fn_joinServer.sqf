/*
	mjb_fnc_joinServer
	Original Author: JoramD
	Modified by: blah2355
	
	Joins a server via the main menu spotlight action using a password saved by CBA
	
	Parameters:
		0: String - Server IP
		1: Number - Server port number
		
	Returns: Nothing
*/

params ["_ip", "_port"];

private _passwordCache = profileNamespace getVariable ["cba_ui_ServerPasswords", [[],[]]];
_passwordCache params ["_addresses", "_passwords"];

private _index = _addresses find (format ["%1:%2", _ip, _port]);
private _password = _passwords param [_index, ""];

connectToServer [_ip, _port, _password];