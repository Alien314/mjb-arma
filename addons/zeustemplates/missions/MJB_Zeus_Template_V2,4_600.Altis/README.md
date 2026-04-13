# MJB-TMF-Universal-Template

# How to use:
1. Press Code (green button) -> Download ZIP to get a copy of the template.
2. Extract the folder and place it in your mission-making folder, typically Documents/Arma3 - Other Profiles/"your username"/mpmissions
3. Rename the .VR-main affix with that of the terrain you desire.
4. When making saves/copies **DO NOT** use "Save As..." in 3DEN editor, it does not save any files aside from the mission.sqm. **Always** Copy and rename the mission folder.
5. Access the file in 3DEN and delete whatever assets you don't need (Note: Deleted assets are a hassle to get back, so plan ahead!).

# Modifying the Arsenal:
Go to initplayerlocal.sqf, comment the top two uncommented lines and uncomment the `0 = execVM 'loadouts\arsenal.sqf';` line.
To make changes to the arsenal, use the `arsenal.sqf` file in the loadouts folder and add/remove desired equipment.
Scroll to the bottom to view what roles have which equipment blocks, preferably with an IDE to make searching through it less of a headache.<br />
SQF highlighting for Notepad++: https://github.com/DannyDorito/npp-sqf

# Modifying starting loadouts:
Uncomment the relevant line(s) in `description.ext`, otherwise the loadouts from retroactive arsenal(mjb arma v2) will be used. Then access the `player_loadout.hpp` file in the loadouts folder and search for your role based off the names in the mission editor.<br /> 
`description.ext` and .hpp files use C++ syntax. (Language -> C -> C++, in Notepad++)

# Existing Missions/Merging
Open a renamed copy of this template in 3DEN Editor (terrain extension must match the merge source).  Scenario > Merge and choose your merge source mission. Any files from the source mission's folder will not be brought along, and have to be manually added to the new template mission you're merging into, or edited into the existing files from the template.

# Init File Changes
When editing existing files put your scripts above the `// Add lines above or comment below line when making changes` line if it's present. Comment the line below it if you need to change the existing scripts in the file.
