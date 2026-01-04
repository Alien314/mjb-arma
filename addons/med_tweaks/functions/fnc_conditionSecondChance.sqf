params ['_unit'];

isPlayer _unit && {(_unit getVariable ['ace_medical_statemachine_fatalInjuriesPlayer',ace_medical_statemachine_fatalInjuriesPlayer]) != 0} || { (_unit getVariable ['ace_medical_statemachine_fatalInjuriesAI',ace_medical_statemachine_fatalInjuriesAI]) != 0 }