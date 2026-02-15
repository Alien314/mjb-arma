class CfgCloudlets {
	class SmokeShellWhite;
	class mjb_impactSmokeShell : SmokeShellWhite {
		//animationSpeed[] = {15,1.5,0.1};
		//color[] = {{0.6,0.6,0.6,0.4},{0.6,0.6,0.6,0.1},{0.6,0.6,0.6,0}};
		//lifeTime = 20;
		moveVelocity[] = {0.2,0.5,0.2};
		MoveVelocityVar[] = {0.7,0.4,0.7};
		size[] = {0.46,14,14.2,14.4,14.6,14.8,15,15.1,15.2,15.3,15.4,15.5,15.6,15.7,15.8,15.9,16,16.1,16.2,16.3,16.4};
		sizeVar = 0.2;
	};
	class SmokeShellWhite2;
	class mjb_impactSmokeShell2 : SmokeShellWhite2 {
		//animationSpeed[] = {15,1.5,0.1};
		//color[] = {[0.6,0.6,0.6,1],[0.6,0.6,0.6,0.5],[0.6,0.6,0.6,0]};
		//lifeTime = 20;
		moveVelocity[] = {0.2,0.5,0.2};
		MoveVelocityVar[] = {0.7,0.4,0.7};
		size[] = {0.46,14,14.2,14.4,14.6,14.8,15,15.1,15.2,15.3,15.4,15.5,15.6,15.7,15.8,15.9,16,16.1,16.2,16.3,16.4};
		sizeVar = 0.2;
	};
};

//class SmokeShellWhiteEffect;
class mjb_SmokeShellWhiteImpactEffect { //: SmokeShellWhiteEffect {
	class mjb_impactSmokeShellWhite {
		intensity = 1;
		interval = 1;
		position[] = {0,0,0};
		simulation = "particles";
		type = "mjb_impactSmokeShell";
	};
	class mjb_impactSmokeShellWhite2 {
		intensity = 1;
		interval = 1;
		position[] = {0,0,0};
		simulation = "particles";
		type = "mjb_impactSmokeShell2";
	};
	class SmokeShell2UW {
		intensity = 1;
		interval = 1;
		position[] = {0,0,0};
		simulation = "particles";
		type = "SmokeShellWhite2UW";
	};
	class SmokeShellUW {
		intensity = 1;
		interval = 1;
		position[] = {0,0,0};
		simulation = "particles";
		type = "SmokeShellWhiteUW";
	};
};
#define SMONKVAR(VAR,VAR2)  SmokeShell##VAR##VAR2
#define SMONKEFF(VAR) class mjb_SmokeShell##VAR##ImpactEffect { \
	class mjb_impactSmokeShell { \
		intensity = 1; \
		interval = 1; \
		position[] = {0,0,0}; \
		simulation = "particles"; \
		type = "mjb_impactSmokeShell"; \
	}; \
	class mjb_impactSmokeShell2 { \
		intensity = 1; \
		interval = 1; \
		position[] = {0,0,0}; \
		simulation = "particles"; \
		type = "mjb_impactSmokeShell2"; \
	}; \
	class SmokeShell2UW { \
		intensity = 1; \
		interval = 1; \
		position[] = {0,0,0}; \
		simulation = "particles"; \
		type = QUOTE(SMONKVAR(VAR,2UW)); \
	}; \
	class SmokeShellUW { \
		intensity = 1; \
		interval = 1; \
		position[] = {0,0,0}; \
		simulation = "particles"; \
		type = QUOTE(SMONKVAR(VAR,UW)); \
	}; \
}

SMONKEFF(Blue);
SMONKEFF(Green);
SMONKEFF(Orange);
SMONKEFF(Purple);
SMONKEFF(Red);
SMONKEFF(Yellow);