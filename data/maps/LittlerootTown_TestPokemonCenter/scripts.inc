.set LOCALID_NURSE, 1

LittlerootTown_TestPokemonCenter_MapScripts::
	.byte 0

LittlerootTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end