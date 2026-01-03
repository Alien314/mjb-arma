
class Extended_InitPost_EventHandlers
{
    // Copy below block for each unit class in your group compositions.
    class mjb_O_customSoldier { // class to add role to, (typeOf unit)
        class varInit {
            // gear assignment, third argument is the role to add
            init = "params ['_unit']; if !(local _unit) exitWith {}; [_unit, 'example_enemy', 'r'] call tmf_assigngear_fnc_assigngear;"; 
        };
    };//*/
    class mjb_O_customSoldier_mg {
        class varInit {
            init = "params ['_unit']; if !(local _unit) exitWith {}; [_unit, 'example_enemy', 'mg'] call tmf_assigngear_fnc_assigngear;"; 
        };
    };
};