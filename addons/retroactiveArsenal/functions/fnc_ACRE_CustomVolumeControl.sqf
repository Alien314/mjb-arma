params ['_volumeLevel']; // [-2, -1, 0, 1, 2] from ACRE

private _voiceLevel = if (!isNil "mjb_CustomVolumeControl" && {mjb_CustomVolumeControl isEqualType {}}) then {
    _this call mjb_CustomVolumeControl
} else {
    linearConversion [-2,2,_volumeLevel,mjb_acreCustomCurveMin,mjb_acreCustomCurveMax,true]
};

_voiceLevel