

// Tarkov Vests

  #define VESTLGT(NAME) \
  class ##NAME## : vest_camo_base { \
    class ItemInfo : vestItem { \
      containerClass = "Supply140"; \
      class HitpointsProtectionInfo { \
          class Abdomen {armor = 20; hitpointName = "HitAbdomen"; passThrough = 0.2;}; \
          delete Arms; \
          class Body {hitpointName = "HitBody"; passThrough = 0.2;}; \
          class Chest {armor = 20; hitpointName = "HitChest"; passThrough = 0.2;}; \
          class Diaphragm {armor = 20; hitpointName = "HitDiaphragm"; passThrough = 0.2;}; \
          delete Neck; \
      }; \
    }; \
  };
          /*class Abdomen {armor = 16; hitpointName = "HitAbdomen"; passThrough = 0.3;}; \
          delete Arms; \
          class Body {delete armor; hitpointName = "HitBody"; passThrough = 0.3;}; \
          class Chest {armor = 16; hitpointName = "HitChest"; passThrough = 0.3;}; \
          class Diaphragm {armor = 16; hitpointName = "HitDiaphragm"; passThrough = 0.3;}; \
          delete Neck; \*/

  #define VESTMED(NAME) \
  class ##NAME## : vest_camo_base { \
    class ItemInfo : vestItem { \
      containerClass = "Supply140"; \
      class HitpointsProtectionInfo { \
          class Abdomen {armor = 20; hitpointName = "HitAbdomen"; passThrough = 0.2;}; \
          delete Arms; \
          class Body {hitpointName = "HitBody"; passThrough = 0.2;}; \
          class Chest {armor = 20; hitpointName = "HitChest"; passThrough = 0.2;}; \
          class Diaphragm {armor = 20; hitpointName = "HitDiaphragm"; passThrough = 0.2;}; \
          delete Neck; \
      }; \
    }; \
  };

  #define VESTHEA(NAME) \
  class ##NAME## : vest_camo_base { \
    class ItemInfo : vestItem { \
      containerClass = "Supply120"; \
      class HitpointsProtectionInfo { \
          class Abdomen {armor = 24; hitpointName = "HitAbdomen"; passThrough = 0.1;}; \
          delete Arms; \
          class Body {hitpointName = "HitBody"; passThrough = 0.1;}; \
          class Chest {armor = 24; hitpointName = "HitChest"; passThrough = 0.1;}; \
          class Diaphragm {armor = 24; hitpointName = "HitDiaphragm"; passThrough = 0.1;}; \
          delete Neck; \
      }; \
    }; \
  };

  #define VESTHVY(NAME) \
  class ##NAME## : vest_camo_base { \
    class ItemInfo : vestItem { \
      containerClass = "Supply100"; \
      class HitpointsProtectionInfo { \
          class Abdomen {armor = 24; hitpointName = "HitAbdomen"; passThrough = 0.1;}; \
          class Arms {armor = 8; hitpointName = "HitArms"; passThrough = 0.5;}; \
          class Body {hitpointName = "HitBody"; passThrough = 0.1;}; \
          class Chest {armor = 24; hitpointName = "HitChest"; passThrough = 0.1;}; \
          class Diaphragm {armor = 24; hitpointName = "HitDiaphragm"; passThrough = 0.1;}; \
          class Neck {armor = 8; hitpointName = "HitNeck"; passThrough = 0.5;}; \
      }; \
    }; \
  };

  class vest_camo_base;
  class Vest_NoCamo_Base;
  class vestItem;

  VESTLGT(V_PlateCarrier1_blk);
  class V_PlateCarrier1_rgr : Vest_NoCamo_Base {
    class ItemInfo : vestItem {
      containerClass = "Supply140";
      class HitpointsProtectionInfo {
          class Abdomen {armor = 20; hitpointName = "HitAbdomen"; passThrough = 0.2;};
          class Body {hitpointName = "HitBody"; passThrough = 0.2;};
          class Chest {armor = 20; hitpointName = "HitChest"; passThrough = 0.2;};
          class Diaphragm {armor = 20; hitpointName = "HitDiaphragm"; passThrough = 0.2;};
      };
    };
  };

  VESTMED(6B3_vest);
  VESTMED(6b5Flora);
  VESTMED(6b5Khaki_vest);
  VESTMED(A18_vest);
  VESTMED(AVS_vest);

  VESTMED(Def2_vest);
  VESTMED(def2Assault_vest);
  VESTMED(def2Bearing_vest);
  VESTMED(def2BlackRock_vest);
  VESTMED(def2D3CRX_vest);
  VESTMED(def2MK3_vest);
  VESTMED(def2Thunderbolt_vest);
  VESTMED(def2Triton_vest);
  VESTMED(def2TV109_vest);

  VESTMED(Gjel_vest);
  VESTMED(GjelAssault_vest);
  VESTMED(GjelBearing_vest);
  VESTMED(GjelBlackRock_vest);
  VESTMED(GjelD3CRX_vest);
  VESTMED(GjelMK3_vest);
  VESTMED(GjelThunderbolt_vest);
  VESTMED(GjelTriton_vest);
  VESTMED(GjelTV109_vest);

  VESTMED(KorundVMAssault_vest);
  VESTMED(KorundVMBearing_vest);
  VESTMED(KorundVMBlackRock_vest);
  VESTMED(KorundVMD3CRX_vest);
  VESTMED(korundvm_vest);
  VESTMED(KorundVMMK3_vest);
  VESTMED(KorundVMThunderbolt_vest);
  VESTMED(KorundVMTriton_vest);
  VESTMED(KorundVMTV109_vest);

  VESTMED(M1_vest);
  VESTMED(M2_vest);
  VESTMED(TV110_vest);

  VESTMED(Thorcrv_vest);
  VESTMED(ThorcrvAssault_vest);
  VESTMED(ThorcrvBearing_vest);
  VESTMED(ThorcrvBlackRock_vest);
  VESTMED(ThorcrvD3CRX_vest);
  VESTMED(ThorcrvMK3_vest);
  VESTMED(ThorcrvThunderbolt_vest);
  VESTMED(ThorcrvTriton_vest);
  VESTMED(ThorcrvTV109_vest);


  VESTMED(Trooper_vest);
  VESTMED(TrooperAssault_vest);
  VESTMED(TrooperBearing_vest);
  VESTMED(TrooperBlackRock_vest);
  VESTMED(TrooperD3CRX_vest);
  VESTMED(TrooperMK3_vest);
  VESTMED(TrooperThunderbolt_vest);
  VESTMED(TrooperTriton_vest);
  VESTMED(TrooperTV109_vest);

  VESTLGT(Module3m_vest);
  VESTLGT(Module3mAssault_vest);
  VESTLGT(Module3mBearing_vest);
  VESTLGT(Module3mBlackRock_vest);
  VESTLGT(Module3mD3CRX_vest);
  VESTLGT(Module3mMK3_vest);
  VESTLGT(Module3mThunderbolt_vest);
  VESTLGT(Module3mTriton_vest);
  VESTLGT(Module3mTV109_vest);

  VESTHEA(RedutM_vest);
  VESTHEA(RedutMAssault_vest);
  VESTHEA(RedutMBearing_vest);
  VESTHEA(RedutMBlackRock_vest);
  VESTHEA(RedutMD3CRX_vest);
  VESTHEA(RedutMMK3_vest);
  VESTHEA(RedutMThunderbolt_vest);
  VESTHEA(RedutMTriton_vest);
  VESTHEA(RedutMTV109_vest);

  VESTHEA(Slick_vest);
  VESTHEA(SlickAssault_vest);
  VESTHEA(SlickBearing_vest);
  VESTHEA(SlickBlackRock_vest);
  VESTHEA(SlickD3CRX_vest);
  VESTHEA(SlickMK3_vest);
  VESTHEA(SlickThunderbolt_vest);
  VESTHEA(SlickTriton_vest);
  VESTHEA(SlickTV109_vest);
