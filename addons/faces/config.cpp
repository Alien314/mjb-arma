class CfgPatches
{
	class Faces
	{
        author = "SuperJam";
        hideName=0;
		units[]={};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]={};
	};
};

// class New_Face_01: WhiteHead_01 // 'New_Face_01' is the classname we wish to give our face - feel free to change it, by all means. Avoid spaces. Don't forget, you'll need to add the classname it's inheriting from afterwards (New_Face_01 : Whitehead_01), which needs to be defined (like above ^^). 
// {
//     displayname="New Face 01"; // Between the quotation marks, add the name of your face. This is how it will appear in the Virtual Arsenal etc. This can also begin with the prefix '$STR' (e.g. "$STR_New_Face_01"); but that's for localization purposes, I won't get bogged down in those details here. I only mention it, in case you see it elsewhere and wonder what it's all about.
//     dlc="My_Amazing_Mod"; // You'll probably just want to delete this line. But if you want your face to have a DLC symbol, you'll need to add another config entry. Let's not worry about this right now! 
//     texture="Path_to_my_Texture.paa"; // This is a very important line! Be sure to check it for typos. An example path to the texture file could look something like this: "\Resist\Heads\Data\Steinacher_co.paa". This would mean, we have a PBO entitled 'Resist', with a folder in it entitled 'Heads', and a folder in that entitled 'Data', and, finally, in that, a .paa file entitled 'Steinacher_co.paa'. I would recommend adding the '_co' suffix for the main colour texture you've created. 
//     head="DefaultHead_A3"; // The actual model for your custom face. For instance, if you used Stavrou's head, with the pony tail, the physical shape of the head would be different and therefore, would have a different entry here. Most just use the default head defined here.
//     identityTypes[]={}; // This is used to identify which units will have your custom face by default; you can leave it alone, it's not really important for what you're trying to achieve.
//     author="Kydoimos"; // Your name goes here :) 
//     material="Path_to_my_Material.rvmat"; // This is another very important line! Depending on just how good you want your face to look, you may want to add a custom RVMAT, with accompanying specular (SMDI) and normal map (NOHQ) textures. Though a vital part of custom faces, I really can't go into too much detail here, as it's quite an in-depth subject and an art form in its own right! If you've only made minor changes to an existing face texture, you should be able to get away with inheriting the standard RVMAT - which you can do by deleting this line entirely. 
//     textureHL="\A3\Characters_F\Heads\Data\hl_white_bald_co.paa"; // Path to texture for hands and legs (HL). You shouldn't need to change this.
//     materialHL="\A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat"; // Path to material (RVMAT) for hands and legs (HL). You shouldn't need to change this.
//     textureHL2="\A3\Characters_F\Heads\Data\hl_white_bald_co.paa"; // Second path (anyone know why there's an HL2?) to texture for hands and legs (HL). You shouldn't need to change this.
//     materialHL2="\A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat"; // Second path (anyone know why there's an HL2?) to material for hands and legs (HL). You shouldn't need to change this.
//     materialWounded1="Path_to_Face_Material_when_Wounded.rvmat"; // Path to a wounded face texture. I'd recommend using the same path as the 'material=' path for your face, if you want an easy ride. Add a wounded texture if you fancy getting a bit more creative.
//     materialWounded2="Path_to_Face_Material_when_Wounded.rvmat"; // Second path to a wounded face texture (again, not too sure why we have two; though I'm sure some bright spark will let me know! :D)
// };

class CfgFaces
{
	class Default
	{
		class Custom;
	};
	class Man_A3: Default
	{
		class Default;
		class WhiteHead_01;
        class Beagle_Troska: WhiteHead_01 {
            displayname="Beagle (Troska)";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\beagle_troska.paa";
        };
		class Westonsammy: WhiteHead_01 {
            displayname="Westonsammy";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\westonsammy.paa";
        };
		class Banzer: WhiteHead_01 {
            displayname="Banzer";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\banzer.paa";
        };
		class FaceThink: WhiteHead_01 {
            displayname="FaceThink";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\facethink.paa";
        };
		class HankHill: WhiteHead_01 {
            displayname="HankHill";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\hank.paa";
        };
        class Ocelot: WhiteHead_01 {
            displayname="Ocelot";
            author="SuperJam (jdcaperon)";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\ocelot.paa";
        };
		class Mongobeef: WhiteHead_01 {
            displayname="Mongobeef";
            author="Mongobeef";
            head="DefaultHead_A3";
            texture="z\mjb\addons\faces\data\facemongo.paa";
        };
	};
};