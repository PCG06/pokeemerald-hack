#include "global.h"
#include "gpu_regs.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "rom6.h"
#include "strings.h"
#include "party_menu.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "secret_base.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "metatile_behavior.h"
#include "string_util.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"
#include "constants/vars.h"

extern struct MapPosition gPlayerFacingPosition;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

extern const struct SpriteTemplate gUnknown_0858E600;
extern const struct SpriteTemplate gUnknown_0858E618;
extern const struct SpriteTemplate gUnknown_0858E630;

extern u8 EventScript_275A86[];
extern u8 EventScript_275ADF[];
extern u8 EventScript_275B38[];

extern const struct OamData gEventObjectBaseOam_32x8;

extern const u16 gTilesetPalettes_SecretBase[][16];

void sub_80F9C90(u8);
void sub_80F9DFC(u8);

void Task_SecretBasePCTurnOn(u8);

void Task_PopSecretBaseBalloon(u8);
void DoBalloonSoundEffect(s16);

void Task_WateringBerryTreeAnim_1(u8);
void Task_WateringBerryTreeAnim_2(u8);
void Task_WateringBerryTreeAnim_3(u8);

void sub_80F9C44(TaskFunc, u16, u16, u8);

void FieldCallback_SecretBaseCave(void);
static void CaveEntranceSpriteCallback1(struct Sprite *);
static void CaveEntranceSpriteCallback2(struct Sprite *);
static void CaveEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseCaveFieldEffect(void);

void FieldCallback_SecretBaseTree(void);
static void TreeEntranceSpriteCallback1(struct Sprite *);
static void TreeEntranceSpriteCallback2(struct Sprite *);
static void TreeEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseTreeFieldEffect(void);

void FieldCallback_SecretBaseShrub(void);
static void ShrubEntranceSpriteCallback1(struct Sprite *);
static void ShrubEntranceSpriteCallback2(struct Sprite *);
static void ShrubEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseShrubFieldEffect(void);

void SpriteCB_SandPillar_0(struct Sprite *);
void SpriteCB_SandPillar_1(struct Sprite *);
void SpriteCB_SandPillar_2(struct Sprite *);

const u8 gSpriteImage_858D978[] = INCBIN_U8("graphics/unknown/858E588/0.4bpp");
const u8 gSpriteImage_858D9F8[] = INCBIN_U8("graphics/unknown/858E588/1.4bpp");
const u8 gSpriteImage_858DA78[] = INCBIN_U8("graphics/unknown/858E588/2.4bpp");
const u8 gSpriteImage_858DAF8[] = INCBIN_U8("graphics/unknown/858E588/3.4bpp");
const u8 gSpriteImage_858DB78[] = INCBIN_U8("graphics/unknown/858E588/4.4bpp");

const u8 gUnusedEmptySpace_858DBF8[32] = {0};

const u16 gFieldEffectObjectPalette7[] = INCBIN_U16("graphics/event_objects/palettes/field_effect_object_palette_07.gbapal");
const u8 gSpriteImage_858DC38[] = INCBIN_U8("graphics/unknown/858E5D8/0.4bpp");
const u8 gSpriteImage_858DCB8[] = INCBIN_U8("graphics/unknown/858E5D8/1.4bpp");
const u8 gSpriteImage_858DD38[] = INCBIN_U8("graphics/unknown/858E5D8/2.4bpp");
const u8 gSpriteImage_858DDB8[] = INCBIN_U8("graphics/unknown/858E5D8/3.4bpp");
const u8 gSpriteImage_858DE38[] = INCBIN_U8("graphics/unknown/858E5D8/4.4bpp");
const u8 gSpriteImage_858DEB8[] = INCBIN_U8("graphics/unknown/858E5B0/0.4bpp");
const u8 gSpriteImage_858DF38[] = INCBIN_U8("graphics/unknown/858E5B0/1.4bpp");
const u8 gSpriteImage_858DFB8[] = INCBIN_U8("graphics/unknown/858E5B0/2.4bpp");
const u8 gSpriteImage_858E038[] = INCBIN_U8("graphics/unknown/858E5B0/3.4bpp");
const u8 gSpriteImage_858E0B8[] = INCBIN_U8("graphics/unknown/858E5B0/4.4bpp");
const u8 gSpriteImage_858E138[] = INCBIN_U8("graphics/unknown/858E5B0/5.4bpp");
const u16 gFieldEffectObjectPalette8[] = INCBIN_U16("graphics/event_objects/palettes/field_effect_object_palette_08.gbapal");
const u8 gSpriteImage_858E1D8[] = INCBIN_U8("graphics/unknown/858E674/0.4bpp");
const u8 gSpriteImage_858E2D8[] = INCBIN_U8("graphics/unknown/858E674/1.4bpp");
const u8 gSpriteImage_858E3D8[] = INCBIN_U8("graphics/unknown/858E674/2.4bpp");

const struct OamData gOamData_858E4D8 =
{
    .y = 0,
    .x = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const union AnimCmd gSpriteAnim_858E4E0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_858E4F8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_858E510[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_858E528[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_858E540[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_858E558[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_858E570[] =
{
    gSpriteAnim_858E4E0,
};

const union AnimCmd *const gSpriteAnimTable_858E574[] =
{
    gSpriteAnim_858E4F8,
    gSpriteAnim_858E510,
    gSpriteAnim_858E528,
    gSpriteAnim_858E540,
};

const union AnimCmd *const gSpriteAnimTable_858E584[] =
{
    gSpriteAnim_858E558,
};

const struct SpriteFrameImage gUnknown_858E588[] = 
{
    {gSpriteImage_858D978, 0x80},
    {gSpriteImage_858D9F8, 0x80},
    {gSpriteImage_858DA78, 0x80},
    {gSpriteImage_858DAF8, 0x80},
    {gSpriteImage_858DB78, 0x80},
};

const struct SpriteFrameImage gUnknown_858E5B0[] = 
{
    {gSpriteImage_858DEB8, 0x80},
    {gSpriteImage_858DF38, 0x80},
    {gSpriteImage_858DFB8, 0x80},
    {gSpriteImage_858E038, 0x80},
    {gSpriteImage_858E0B8, 0x80},
};

const struct SpriteFrameImage gUnknown_858E5D8[] = 
{
    {gSpriteImage_858DC38, 0x80},
    {gSpriteImage_858DCB8, 0x80},
    {gSpriteImage_858DD38, 0x80},
    {gSpriteImage_858DDB8, 0x80},
    {gSpriteImage_858DE38, 0x80},
};

const struct SpriteTemplate gUnknown_0858E600 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1003,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E570,
    .images = gUnknown_858E588,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CaveEntranceSpriteCallback1,
};

const struct SpriteTemplate gUnknown_0858E618 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1008,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E574,
    .images = gUnknown_858E5B0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TreeEntranceSpriteCallback1,
};

const struct SpriteTemplate gUnknown_0858E630 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1008,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E584,
    .images = gUnknown_858E5D8,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ShrubEntranceSpriteCallback1,
};

const struct SpritePalette gFieldEffectObjectPaletteInfo7 = {gFieldEffectObjectPalette7, 0x1003};
const struct SpritePalette gFieldEffectObjectPaletteInfo8 = {gFieldEffectObjectPalette8, 0x1008};

const struct OamData gOamData_858E658 =
{
    .x = 0,
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const union AnimCmd gSpriteAnim_858E660[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_858E670[] =
{
    gSpriteAnim_858E660,
};

const struct SpriteFrameImage gUnknown_0858E674[] =
{
    {gSpriteImage_858E1D8, 0x100},// sizeof()?
    {gSpriteImage_858E2D8, 0x100},
    {gSpriteImage_858E3D8, 0x100},
};

const struct SpriteTemplate gUnknown_0858E68C =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x100E,
    .oam = &gOamData_858E658,
    .anims = gSpriteAnimTable_858E670,
    .images = gUnknown_0858E674,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SandPillar_0,
};

// This uses one of the secret base palettes, so there is no "field_effect_object_palette_09.pal" file.
const struct SpritePalette gFieldEffectObjectPaletteInfo9 = {gTilesetPalettes_SecretBase[5], 0x100E};

static const u8 gSpriteImage_858E6AC[] = INCBIN_U8("graphics/unknown/858E84C/0.4bpp");
static const u8 gSpriteImage_858E72C[] = INCBIN_U8("graphics/unknown/858E84C/1.4bpp");
static const u8 gSpriteImage_858E7AC[] = INCBIN_U8("graphics/unknown/858E84C/2.4bpp");
static const u16 gUnknown_0858E82C[] = INCBIN_U16("graphics/unknown/unknown_58E82C.gbapal");

static const struct SpriteFrameImage gUnknown_0858E84C[] =
{
    {gSpriteImage_858E6AC, sizeof(gSpriteImage_858E6AC)},
    {gSpriteImage_858E72C, sizeof(gSpriteImage_858E72C)},
    {gSpriteImage_858E7AC, sizeof(gSpriteImage_858E7AC)},
};

static const struct SpritePalette gUnknown_0858E864 = {gUnknown_0858E82C, 0x1000};// sizeof(gUnknown_0858E82C)?

static const union AnimCmd gSpriteAnim_858E86C[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(2, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gSpriteAnimTable_858E87C[] =
{
    gSpriteAnim_858E86C,
};

static const struct SpriteTemplate gUnknown_0858E880 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1000,
    .oam = &gEventObjectBaseOam_32x8,
    .anims = gSpriteAnimTable_858E87C,
    .images = gUnknown_0858E84C,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// TODO: name these functions and arguments
void sub_80F9BCC(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9C90, a0, a1, a2);
}

void sub_80F9BF4(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9DFC, a0, a1, a2);
}

bool8 sub_80F9C1C(void)
{
    return FuncIsActiveTask(sub_80F9C90);
}

bool8 sub_80F9C30(void)
{
    return FuncIsActiveTask(sub_80F9DFC);
}

void sub_80F9C44(void (*taskfunc) (u8), u16 a1, u16 a2, u8 a3)
{
    u16 tempA, tempB;

    u8 taskId = CreateTask(taskfunc, a3);

    gTasks[taskId].data[0] = 0;

    tempA = 16;
    if (a1 != 0)
    {
        tempA = a1;
    }
    gTasks[taskId].data[1] = tempA;

    tempB = 20;
    if (a1 != 0)
    {
        tempB = a1;
    }
    gTasks[taskId].data[2] = tempB;

    gTasks[taskId].func(taskId);
}

#ifdef NONMATCHING
void sub_80F9C90(u8 taskId)
{
    //
    struct Task *task = &gTasks[taskId];
    //u16 ta, tb;

    switch(task->data[0])
    {
    case 0:// correct
        task->data[3] = 0x78;
        task->data[4] = 0x78;
        task->data[5] = 0x50;
        task->data[6] = 0x51;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, task->data[3] << 8 | task->data[4]);
        SetGpuReg(REG_OFFSET_WIN0H, task->data[5] << 8 | task->data[6]);
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0);

        break;

    case 1:// correct
        task->data[7] = GetGpuReg(REG_OFFSET_BLDCNT);
        task->data[8] = GetGpuReg(REG_OFFSET_BLDY);

        SetGpuReg(REG_OFFSET_BLDCNT, 0xBF);
        SetGpuReg(REG_OFFSET_BLDY, 0x10);

        break;

    case 2:
        //r5 = 0 somewhere in here
        task->data[3] -= task->data[1];
        task->data[4] += task->data[1];

        if (task->data[3] <= 0 || task->data[4] > 0xEF)
        {
            //
            task->data[3] = 0;// r5
            task->data[4] = 0xF0;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->data[7]);
            //BlendPalettes(0xFFFF, 0, 0);
            BlendPalettes(-1, 0, 0);// 0xFFFFFFFF ?
            *gPlttBufferFaded = 0;// r5
        }
        //SetGpuReg(REG_OFFSET_WIN0H, task->data[3] << 8 | task->data[4]);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));

        //break;
        // can I ternary this? NO stupid
        if (task->data[3] != 0) return;
        break;

    case 3:
        task->data[5] -= task->data[2];
        task->data[6] += task->data[2];

        if (task->data[5] <= 0 || task->data[2] > 0x9F)
        {
            //
            task->data[5] = 0;
            task->data[6] = 0xA0;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        //SetGpuReg(REG_OFFSET_WIN0V, task->data[5] << 8 | task->data[6]);
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));

        if (task->data[5] != 0) return;
        break;

        //break;

    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->data[7]);
        DestroyTask(taskId);
        return;
    }
    //
    task->data[0] += 1;
}
#else
NAKED
void sub_80F9C90(u8 taskId)
{
    asm_unified("\tpush {r4,r5,lr}\n"
                "\tlsls r0, 24\n"
                "\tlsrs r5, r0, 24\n"
                "\tlsls r0, r5, 2\n"
                "\tadds r0, r5\n"
                "\tlsls r0, 3\n"
                "\tldr r1, =gTasks\n"
                "\tadds r4, r0, r1\n"
                "\tmovs r1, 0x8\n"
                "\tldrsh r0, [r4, r1]\n"
                "\tcmp r0, 0x1\n"
                "\tbeq _080F9D10\n"
                "\tcmp r0, 0x1\n"
                "\tbgt _080F9CB8\n"
                "\tcmp r0, 0\n"
                "\tbeq _080F9CC2\n"
                "\tb _080F9DDE\n"
                "\t.pool\n"
                "_080F9CB8:\n"
                "\tcmp r0, 0x2\n"
                "\tbeq _080F9D32\n"
                "\tcmp r0, 0x3\n"
                "\tbeq _080F9D94\n"
                "\tb _080F9DDE\n"
                "_080F9CC2:\n"
                "\tmovs r0, 0x78\n"
                "\tstrh r0, [r4, 0xE]\n"
                "\tstrh r0, [r4, 0x10]\n"
                "\tmovs r0, 0x50\n"
                "\tstrh r0, [r4, 0x12]\n"
                "\tmovs r0, 0x51\n"
                "\tstrh r0, [r4, 0x14]\n"
                "\tmovs r1, 0x80\n"
                "\tlsls r1, 6\n"
                "\tmovs r0, 0\n"
                "\tbl SetGpuRegBits\n"
                "\tldrh r1, [r4, 0xE]\n"
                "\tlsls r1, 8\n"
                "\tldrh r0, [r4, 0x10]\n"
                "\torrs r1, r0\n"
                "\tlsls r1, 16\n"
                "\tlsrs r1, 16\n"
                "\tmovs r0, 0x40\n"
                "\tbl SetGpuReg\n"
                "\tldrh r1, [r4, 0x12]\n"
                "\tlsls r1, 8\n"
                "\tldrh r0, [r4, 0x14]\n"
                "\torrs r1, r0\n"
                "\tlsls r1, 16\n"
                "\tlsrs r1, 16\n"
                "\tmovs r0, 0x44\n"
                "\tbl SetGpuReg\n"
                "\tmovs r0, 0x48\n"
                "\tmovs r1, 0x3F\n"
                "\tbl SetGpuReg\n"
                "\tmovs r0, 0x4A\n"
                "\tmovs r1, 0\n"
                "\tbl SetGpuReg\n"
                "\tb _080F9DEE\n"
                "_080F9D10:\n"
                "\tmovs r0, 0x50\n"
                "\tbl GetGpuReg\n"
                "\tstrh r0, [r4, 0x16]\n"
                "\tmovs r0, 0x54\n"
                "\tbl GetGpuReg\n"
                "\tstrh r0, [r4, 0x18]\n"
                "\tmovs r0, 0x50\n"
                "\tmovs r1, 0xBF\n"
                "\tbl SetGpuReg\n"
                "\tmovs r0, 0x54\n"
                "\tmovs r1, 0x10\n"
                "\tbl SetGpuReg\n"
                "\tb _080F9DEE\n"
                "_080F9D32:\n"
                "\tldrh r0, [r4, 0xE]\n"
                "\tldrh r1, [r4, 0xA]\n"
                "\tsubs r0, r1\n"
                "\tmovs r5, 0\n"
                "\tstrh r0, [r4, 0xE]\n"
                "\tldrh r2, [r4, 0x10]\n"
                "\tadds r1, r2\n"
                "\tstrh r1, [r4, 0x10]\n"
                "\tlsls r0, 16\n"
                "\tcmp r0, 0\n"
                "\tble _080F9D50\n"
                "\tlsls r0, r1, 16\n"
                "\tasrs r0, 16\n"
                "\tcmp r0, 0xEF\n"
                "\tble _080F9D76\n"
                "_080F9D50:\n"
                "\tstrh r5, [r4, 0xE]\n"
                "\tmovs r0, 0xF0\n"
                "\tstrh r0, [r4, 0x10]\n"
                "\tmovs r0, 0x54\n"
                "\tmovs r1, 0\n"
                "\tbl SetGpuReg\n"
                "\tldrh r1, [r4, 0x16]\n"
                "\tmovs r0, 0x50\n"
                "\tbl SetGpuReg\n"
                "\tmovs r0, 0x1\n"
                "\tnegs r0, r0\n"
                "\tmovs r1, 0\n"
                "\tmovs r2, 0\n"
                "\tbl BlendPalettes\n"
                "\tldr r0, =gPlttBufferFaded\n"
                "\tstrh r5, [r0]\n"
                "_080F9D76:\n"
                "\tldrh r1, [r4, 0xE]\n"
                "\tlsls r1, 8\n"
                "\tldrh r0, [r4, 0x10]\n"
                "\torrs r1, r0\n"
                "\tlsls r1, 16\n"
                "\tlsrs r1, 16\n"
                "\tmovs r0, 0x40\n"
                "\tbl SetGpuReg\n"
                "\tmovs r1, 0xE\n"
                "\tldrsh r0, [r4, r1]\n"
                "\tb _080F9DD8\n"
                "\t.pool\n"
                "_080F9D94:\n"
                "\tldrh r0, [r4, 0x12]\n"
                "\tldrh r1, [r4, 0xC]\n"
                "\tsubs r0, r1\n"
                "\tstrh r0, [r4, 0x12]\n"
                "\tldrh r2, [r4, 0x14]\n"
                "\tadds r1, r2\n"
                "\tstrh r1, [r4, 0x14]\n"
                "\tlsls r0, 16\n"
                "\tcmp r0, 0\n"
                "\tble _080F9DB0\n"
                "\tlsls r0, r1, 16\n"
                "\tasrs r0, 16\n"
                "\tcmp r0, 0x9F\n"
                "\tble _080F9DC2\n"
                "_080F9DB0:\n"
                "\tmovs r0, 0\n"
                "\tstrh r0, [r4, 0x12]\n"
                "\tmovs r0, 0xA0\n"
                "\tstrh r0, [r4, 0x14]\n"
                "\tmovs r1, 0x80\n"
                "\tlsls r1, 6\n"
                "\tmovs r0, 0\n"
                "\tbl ClearGpuRegBits\n"
                "_080F9DC2:\n"
                "\tldrh r1, [r4, 0x12]\n"
                "\tlsls r1, 8\n"
                "\tldrh r0, [r4, 0x14]\n"
                "\torrs r1, r0\n"
                "\tlsls r1, 16\n"
                "\tlsrs r1, 16\n"
                "\tmovs r0, 0x44\n"
                "\tbl SetGpuReg\n"
                "\tmovs r1, 0x12\n"
                "\tldrsh r0, [r4, r1]\n"
                "_080F9DD8:\n"
                "\tcmp r0, 0\n"
                "\tbne _080F9DF4\n"
                "\tb _080F9DEE\n"
                "_080F9DDE:\n"
                "\tldrh r1, [r4, 0x16]\n"
                "\tmovs r0, 0x50\n"
                "\tbl SetGpuReg\n"
                "\tadds r0, r5, 0\n"
                "\tbl DestroyTask\n"
                "\tb _080F9DF4\n"
                "_080F9DEE:\n"
                "\tldrh r0, [r4, 0x8]\n"
                "\tadds r0, 0x1\n"
                "\tstrh r0, [r4, 0x8]\n"
                "_080F9DF4:\n"
                "\tpop {r4,r5}\n"
                "\tpop {r0}\n"
                "\tbx r0");
}
#endif

void sub_80F9DFC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    int temp = task->data[0];

    switch (temp)
    {
    case 0:
        gPlttBufferFaded[0] = temp;
        break;

    case 1:
        task->data[3] = 0;
        task->data[4] = 0xF0;
        task->data[5] = 0;
        task->data[6] = 0xA0;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;

    case 2:
        task->data[5] += task->data[2];
        task->data[6] -= task->data[2];

        if (task->data[5] > 0x4F || task->data[6] <= 0x51)
        {
            task->data[5] = 0x50;
            task->data[6] = 0x51;
            SetGpuReg(REG_OFFSET_BLDCNT, 0xBF);
            SetGpuReg(REG_OFFSET_BLDY, 0x10);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));

        if (task->data[5] != 0x50) return;
        break;

    case 3:
        task->data[3] += task->data[1];
        task->data[4] -= task->data[1];

        if (task->data[3] > 0x77 || task->data[4] <= 0x78)
        {
            task->data[3] = 0x78;
            task->data[4] = 0x78;
            BlendPalettes(-1, 0x10, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));

        if (task->data[3] != 0x78) return;
        break;

    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    task->data[0] += 1;
}

//=============================================================================
// fldeff_secretpower.c

void SetCurrentSecretBase(void)
{
    sub_80E9608(&gPlayerFacingPosition, gMapHeader.events);
    sub_80E8B6C();
}

void AdjustSecretPowerSpritePixelOffsets(void)
{
    if (gPlayerAvatar.flags & 0x6)
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
    else
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
}

bool8 SetUpFieldMove_SecretPower(void)
{
    u8 mb;

    sub_80E8BC8();

    if (gSpecialVar_Result == 1 || GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);

    if (MetatileBehavior_IsSecretBaseCave(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseCave;
        return TRUE;
    }

    if (MetatileBehavior_IsSecretBaseTree(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseTree;
        return TRUE;
    }

    if (MetatileBehavior_IsSecretBaseShrub(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseShrub;
        return TRUE;
    }

    return FALSE;
}

void FieldCallback_SecretBaseCave(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_275A86);
}

bool8 FldEff_UseSecretPowerCave(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseCaveFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseCaveFieldEffect;

    return FALSE;
}

static void StartSecretBaseCaveFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_CAVE);
    FieldEffectStart(FLDEFF_SECRET_POWER_CAVE);
}

bool8 FldEff_SecretPowerCave(void)
{
    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&gUnknown_0858E600,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);
    
    return FALSE;
}

static void CaveEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W088);

    sprite->data[0] = 0;
    sprite->callback = CaveEntranceSpriteCallback2;
}

static void CaveEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        sprite->data[0]++;

        if (sprite->data[0] == 20)
            sub_80E8D4C();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = CaveEntranceSpriteCallbackEnd;
    }
}

static void CaveEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_CAVE);
    EnableBothScriptContexts();
}

void FieldCallback_SecretBaseTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_275ADF);
}

bool8 FldEff_UseSecretPowerTree(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseTreeFieldEffect;

    return FALSE;
}

static void StartSecretBaseTreeFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_TREE);
    FieldEffectStart(FLDEFF_SECRET_POWER_TREE);
}

bool8 FldEff_SecretPowerTree(void)
{
    s16 mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y) & 0xFFF;

    if (mb == MB_SECRET_BASE_SPOT_TREE_LEFT)
        gFieldEffectArguments[7] = 0;

    if (mb == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        gFieldEffectArguments[7] = 2;

    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&gUnknown_0858E618,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    if (gFieldEffectArguments[7] == 1 || gFieldEffectArguments[7] == 3)
        sub_80E8D4C();

    return FALSE;
}

static void TreeEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W010);

    sprite->animNum = gFieldEffectArguments[7];
    sprite->data[0] = 0;
    sprite->callback = TreeEntranceSpriteCallback2;
}

static void TreeEntranceSpriteCallback2(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] >= 40)
    {
        if (gFieldEffectArguments[7] == 0 || gFieldEffectArguments[7] == 2)
            sub_80E8D4C();

        sprite->data[0] = 0;
        sprite->callback = TreeEntranceSpriteCallbackEnd;
    }
}

static void TreeEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_TREE);
    EnableBothScriptContexts();
}

void FieldCallback_SecretBaseShrub(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_275B38);
}

bool8 FldEff_UseSecretPowerShrub(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseShrubFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseShrubFieldEffect;

    return FALSE;
}

static void StartSecretBaseShrubFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_SHRUB);
    FieldEffectStart(FLDEFF_SECRET_POWER_SHRUB);
}

bool8 FldEff_SecretPowerShrub(void)
{
    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&gUnknown_0858E630,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    return FALSE;
}

static void ShrubEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W077);

    sprite->data[0] = 0;
    sprite->callback = ShrubEntranceSpriteCallback2;
}

static void ShrubEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        sprite->data[0]++;

        if (sprite->data[0] == 20)
            sub_80E8D4C();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = ShrubEntranceSpriteCallbackEnd;
    }
}

static void ShrubEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_SHRUB);
    EnableBothScriptContexts();
}

u32 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].data[0] = x;
    gTasks[taskId].data[1] = y;
    gTasks[taskId].data[2] = 0;

    return 0;
}

void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[2])
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(data[0], data[1], 548);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(data[0], data[1], 544);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        break;
    case 20:
        MapGridSetMetatileIdAt(data[0], data[1], 548);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        return;
    }

    data[2]++;
}

void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);

    if (!VarGet(VAR_CURRENT_SECRET_BASE))
        MapGridSetMetatileIdAt(x, y, 3616);
    else
        MapGridSetMetatileIdAt(x, y, 3617);

    CurrentMapDrawMetatileAt(x, y);
}

//=============================================================================
// fldeff_decoration.c

void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y)
{
    u8 taskId = CreateTask(Task_PopSecretBaseBalloon, 0);

    gTasks[taskId].data[0] = metatileId;
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 1;
}

void Task_PopSecretBaseBalloon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[3] == 6)
        data[3] = 0;
    else
        data[3]++;

    if (data[3] == 0)
    {
        if (data[4] == 2)
            DoBalloonSoundEffect(data[0]);

        MapGridSetMetatileIdAt(data[1], data[2], data[0] + data[4]);
        CurrentMapDrawMetatileAt(data[1], data[2]);

        if (data[4] == 3)
            DestroyTask(taskId);
        else
            data[4]++;
    }
}

void DoBalloonSoundEffect(s16 metatileId)
{
    switch (metatileId)
    {
    case 824:
        PlaySE(SE_FUUSEN1);
        break;
    case 828:
        PlaySE(SE_FUUSEN2);
        break;
    case 832:
        PlaySE(SE_FUUSEN3);
        break;
    case 552:
        PlaySE(SE_TOY_DANGO);
        break;
    }
}

bool8 FldEff_NopA6FC(void)
{
    return FALSE;
}

bool8 FldEff_NopA700(void)
{
    return FALSE;
}

void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_TOY_KABE);
    MapGridSetMetatileIdAt(x, y, 630);
    MapGridSetMetatileIdAt(x, y - 1, 622);
    CurrentMapDrawMetatileAt(x, y);
    CurrentMapDrawMetatileAt(x, y - 1);
}

void Task_ShatterSecretBaseBreakableDoor(u8 taskId)
{
    if (gTasks[taskId].data[0] == 7)
    {
        DoSecretBaseBreakableDoorEffect(gTasks[taskId].data[1], gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0]++;
    }
}

void ShatterSecretBaseBreakableDoor(s16 x, s16 y)
{
    u8 dir = GetPlayerFacingDirection();

    if (dir == DIR_SOUTH)
    {
        DoSecretBaseBreakableDoorEffect(x, y);
    }
    else if (dir == DIR_NORTH)
    {
        u8 taskId = CreateTask(Task_ShatterSecretBaseBreakableDoor, 5);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = x;
        gTasks[taskId].data[2] = y;
    }
}

#define tMetatileID data[0]
void Task_SecretBaseMusicNoteMatSound(u8 taskId)
{
    if (gTasks[taskId].data[1] == 7)
    {
        switch (gTasks[taskId].tMetatileID)
        {
        case 632:
            PlaySE(SE_TOY_C);
            break;
        case 633:
            PlaySE(SE_TOY_D);
            break;
        case 634:
            PlaySE(SE_TOY_E);
            break;
        case 635:
            PlaySE(SE_TOY_F);
            break;
        case 636:
            PlaySE(SE_TOY_G);
            break;
        case 637:
            PlaySE(SE_TOY_A);
            break;
        case 638:
            PlaySE(SE_TOY_B);
            break;
        case 691:
            PlaySE(SE_TOY_C1);
            break;
        }

        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[1]++;
    }
}

void PlaySecretBaseMusicNoteMatSound(s16 metatileId)
{
    u8 taskId = CreateTask(Task_SecretBaseMusicNoteMatSound, 5);

    gTasks[taskId].tMetatileID = metatileId;
    gTasks[taskId].data[1] = 0;
}
#undef tMetatileID

void SpriteCB_GlitterMatSparkle(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] == 8)
        PlaySE(SE_W215);

    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}

void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x;
    s16 y = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y;
    u8 spriteId;

    sub_80930E0(&x, &y, 8, 4);

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[22], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].oam.paletteNum = 5;
        gSprites[spriteId].callback = SpriteCB_GlitterMatSparkle;
        gSprites[spriteId].data[0] = 0;
    }
}

bool8 FldEff_SandPillar(void)
{
    s16 x, y;

    ScriptContext2_Enable();
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    gFieldEffectArguments[5] = x;
    gFieldEffectArguments[6] = y;

    switch (GetPlayerFacingDirection())
    {
    case DIR_SOUTH:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 32,
                     0);

        break;

    case DIR_NORTH:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y,
                     148);
        
        break;
    
    case DIR_WEST:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x - 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);
    
        break;
    
    case DIR_EAST:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 24,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);
    
        break;
    }

    return FALSE;
}

void SpriteCB_SandPillar_0(struct Sprite *sprite)
{
    PlaySE(SE_W088);

    if (MapGridGetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1) == 646)
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, 3586);
    else
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, 644);
    
    MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], 522);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
    
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_SandPillar_1;
}

void SpriteCB_SandPillar_1(struct Sprite *sprite)
{
    if (sprite->data[0] < 18)
    {
        sprite->data[0]++;
    }
    else
    {
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], 3724);
        CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_SandPillar_2;
    }
}

void SpriteCB_SandPillar_2(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SAND_PILLAR);
    EnableBothScriptContexts();
}

void GetShieldToyTVDecorationInfo(void)
{
    s16 x, y;
    s32 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    metatileId = MapGridGetMetatileIdAt(x, y);

    switch (metatileId)
    {
    case 822:
        ConvertIntToDecimalStringN(gStringVar1, 100, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(gStringVar2, gText_Gold);

        gSpecialVar_Result = 0;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_0x40EE, VarGet(VAR_0x40EE) | 0x10);

        break;
    
    case 734:
        ConvertIntToDecimalStringN(gStringVar1, 50, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringCopy(gStringVar2, gText_Silver);

        gSpecialVar_Result = 0;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_0x40EE, VarGet(VAR_0x40EE) | 0x20);

        break;
    
    case 756:
        gSpecialVar_Result = 1;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_0x40EE, VarGet(VAR_0x40EE) | 0x80);

        break;
    
    case 757:
        gSpecialVar_Result = 2;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_0x40EE, VarGet(VAR_0x40EE) | 0x80);

        break;
    
    case 758:
        gSpecialVar_Result = 3;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_0x40EE, VarGet(VAR_0x40EE) | 0x80);

        break;
    }
}

#ifdef NONMATCHING
// 
bool8 sub_80FADE4(u16 arg0, u8 arg1)
{
    //
    if (CurrentMapIsSecretBase())
    {
    //    return TRUE;
        if (arg1 == 0)
        {
            //
            if ((u16)(arg0 + 0xfffffd7b) <= 1 || (arg0 == 0x237))
                return TRUE;
            //if (arg0 == 0x237)
            //else    return FALSE;
        }
        else
        {
            //
            if (arg0 == 0x28d || arg0 == 0x23f)
                return TRUE;
            //return FALSE;
        }
    }
    return FALSE;
}
#else
NAKED
bool8 sub_80FADE4(u16 arg0, u8 arg1)
{
    asm_unified("\tpush {r4-r6,lr}\n"
                "\tlsls r0, 16\n"
                "\tlsrs r4, r0, 16\n"
                "\tadds r6, r4, 0\n"
                "\tlsls r1, 24\n"
                "\tlsrs r5, r1, 24\n"
                "\tbl CurrentMapIsSecretBase\n"
                "\tlsls r0, 24\n"
                "\tcmp r0, 0\n"
                "\tbeq _080FAE28\n"
                "\tcmp r5, 0\n"
                "\tbne _080FAE1C\n"
                "\tldr r1, =0xfffffd7b\n"
                "\tadds r0, r4, r1\n"
                "\tlsls r0, 16\n"
                "\tlsrs r0, 16\n"
                "\tcmp r0, 0x1\n"
                "\tbls _080FAE10\n"
                "\tldr r0, =0x00000237\n"
                "\tcmp r4, r0\n"
                "\tbne _080FAE28\n"
                "_080FAE10:\n"
                "\tmovs r0, 0x1\n"
                "\tb _080FAE2A\n"
                "\t.pool\n"
                "_080FAE1C:\n"
                "\tldr r0, =0x0000028d\n"
                "\tcmp r4, r0\n"
                "\tbeq _080FAE10\n"
                "\tldr r0, =0x0000023f\n"
                "\tcmp r6, r0\n"
                "\tbeq _080FAE10\n"
                "_080FAE28:\n"
                "\tmovs r0, 0\n"
                "_080FAE2A:\n"
                "\tpop {r4-r6}\n"
                "\tpop {r1}\n"
                "\tbx r1\n"
                "\t.pool");
}
#endif

void Task_FieldPoisonEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        data[1] += 2;
        if (data[1] > 8)
            data[0]++;

        break;

    case 1:
        data[1] -= 2;
        if (data[1] == 0)
            data[0]++;

        break;

    case 2:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_MOSAIC, (data[1] << 4) | data[1]);
}

void FldeffPoison_Start(void)
{
    PlaySE(SE_DOKU);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 FldeffPoison_IsActive(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

void Task_WateringBerryTreeAnim_0(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_1;
}

void Task_WateringBerryTreeAnim_1(u8 taskId)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    
    if (!EventObjectIsMovementOverridden(playerEventObj)
        || EventObjectClearHeldMovementIfFinished(playerEventObj))
    {
        sub_808C228(GetPlayerFacingDirection());
        EventObjectSetHeldMovement(playerEventObj, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_2;
    }
}

void Task_WateringBerryTreeAnim_2(u8 taskId)
{
    struct EventObject *playerEventObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    
    if (EventObjectClearHeldMovementIfFinished(playerEventObj))
    {
        s16 value = gTasks[taskId].data[1]++;
        
        if (value < 10)
            EventObjectSetHeldMovement(playerEventObj, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        
        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_3;
    }
}

void Task_WateringBerryTreeAnim_3(u8 taskId)
{
    SetPlayerAvatarTransitionFlags(sub_808BCD0());
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim_0, 80);
}

u8 CreateRecordMixingSprite(void)
{
    u8 spriteId;

    LoadSpritePalette(&gUnknown_0858E864);

    spriteId = CreateSprite(&gUnknown_0858E880, 0, 0, 82);

    if (spriteId == MAX_SPRITES)
    {
        return MAX_SPRITES;
    }
    else
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sub_8092FF0(16, 13, &sprite->pos1.x, &sprite->pos1.y);
        sprite->coordOffsetEnabled = TRUE;
        sprite->pos1.x += 16;
        sprite->pos1.y += 2;
    }

    return spriteId;
}

void DestroyRecordMixingSprite(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].template == &gUnknown_0858E880)
        {
            FreeSpritePalette(&gSprites[i]);
            DestroySprite(&gSprites[i]);
        }
    }
}
