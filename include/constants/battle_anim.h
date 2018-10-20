#ifndef GUARD_CONSTANTS_BATTLE_ANIM_H
#define GUARD_CONSTANTS_BATTLE_ANIM_H

// Sprites start at 10000 and thus must be subtracted of 10000 to account for the true index.
#define GET_TRUE_SPRITE_INDEX(i) ((i - ANIM_SPRITES_START))

// Particle ids.
#define ANIM_SPRITES_START 10000

#define ANIM_TAG_BONE (ANIM_SPRITES_START + 0)
#define ANIM_TAG_SPARK (ANIM_SPRITES_START + 1)
#define ANIM_TAG_PENCIL (ANIM_SPRITES_START + 2)
#define ANIM_TAG_AIR_WAVE (ANIM_SPRITES_START + 3)
#define ANIM_TAG_004 (ANIM_SPRITES_START + 4) // ?
#define ANIM_TAG_SWORD (ANIM_SPRITES_START + 5)
#define ANIM_TAG_SEED (ANIM_SPRITES_START + 6)
#define ANIM_TAG_007 (ANIM_SPRITES_START + 7) // ?
#define ANIM_TAG_008 (ANIM_SPRITES_START + 8) // ?
#define ANIM_TAG_GUST (ANIM_SPRITES_START + 9)
#define ANIM_TAG_ICE_CUBE (ANIM_SPRITES_START + 10)
#define ANIM_TAG_SPARK_2 (ANIM_SPRITES_START + 11)
#define ANIM_TAG_012 (ANIM_SPRITES_START + 12) // ?
#define ANIM_TAG_YELLOW_BALL (ANIM_SPRITES_START + 13)
#define ANIM_TAG_LOCK_ON (ANIM_SPRITES_START + 14)
#define ANIM_TAG_TIED_BAG (ANIM_SPRITES_START + 15)
#define ANIM_TAG_BLACK_SMOKE (ANIM_SPRITES_START + 16)
#define ANIM_TAG_BLACK_BALL (ANIM_SPRITES_START + 17)
#define ANIM_TAG_CONVERSION (ANIM_SPRITES_START + 18)
#define ANIM_TAG_019 (ANIM_SPRITES_START + 19) // ?
#define ANIM_TAG_HORN_HIT (ANIM_SPRITES_START + 20)
#define ANIM_TAG_021 (ANIM_SPRITES_START + 21) // ?
#define ANIM_TAG_022 (ANIM_SPRITES_START + 22) // ?
#define ANIM_TAG_023 (ANIM_SPRITES_START + 23) // ?
#define ANIM_TAG_024 (ANIM_SPRITES_START + 24) // ?
#define ANIM_TAG_025 (ANIM_SPRITES_START + 25) // ?
#define ANIM_TAG_026 (ANIM_SPRITES_START + 26) // ?
#define ANIM_TAG_GLARE (ANIM_SPRITES_START + 27)
#define ANIM_TAG_028 (ANIM_SPRITES_START + 28) // ?
#define ANIM_TAG_SMALL_EMBER (ANIM_SPRITES_START + 29)
#define ANIM_TAG_GRAY_SMOKE (ANIM_SPRITES_START + 30)
#define ANIM_TAG_BLUE_STAR (ANIM_SPRITES_START + 31)
#define ANIM_TAG_032 (ANIM_SPRITES_START + 32) // ?
#define ANIM_TAG_FIRE (ANIM_SPRITES_START + 33)
#define ANIM_TAG_034 (ANIM_SPRITES_START + 34) // ?
#define ANIM_TAG_035 (ANIM_SPRITES_START + 35) // ?
#define ANIM_TAG_036 (ANIM_SPRITES_START + 36) // ?
#define ANIM_TAG_LIGHTNING (ANIM_SPRITES_START + 37)
#define ANIM_TAG_038 (ANIM_SPRITES_START + 38) // ?
#define ANIM_TAG_CLAW_SLASH (ANIM_SPRITES_START + 39)
#define ANIM_TAG_040 (ANIM_SPRITES_START + 40) // ?
#define ANIM_TAG_041 (ANIM_SPRITES_START + 41) // ?
#define ANIM_TAG_042 (ANIM_SPRITES_START + 42) // ?
#define ANIM_TAG_ICE_CHUNK (ANIM_SPRITES_START + 43)
#define ANIM_TAG_044 (ANIM_SPRITES_START + 44) // ?
#define ANIM_TAG_PINK_HEART (ANIM_SPRITES_START + 45) // ?
#define ANIM_TAG_046 (ANIM_SPRITES_START + 46) // ?
#define ANIM_TAG_047 (ANIM_SPRITES_START + 47) // ?
#define ANIM_TAG_048 (ANIM_SPRITES_START + 48) // ?
#define ANIM_TAG_SPARKLE (ANIM_SPRITES_START + 49)
#define ANIM_TAG_050 (ANIM_SPRITES_START + 50) // ?
#define ANIM_TAG_051 (ANIM_SPRITES_START + 51)
#define ANIM_TAG_052 (ANIM_SPRITES_START + 52)
#define ANIM_TAG_053 (ANIM_SPRITES_START + 53)
#define ANIM_TAG_054 (ANIM_SPRITES_START + 54)
#define ANIM_TAG_RED_FIST (ANIM_SPRITES_START + 55)
#define ANIM_TAG_056 (ANIM_SPRITES_START + 56)
#define ANIM_TAG_057 (ANIM_SPRITES_START + 57)
#define ANIM_TAG_058 (ANIM_SPRITES_START + 58)
#define ANIM_TAG_059 (ANIM_SPRITES_START + 59)
#define ANIM_TAG_060 (ANIM_SPRITES_START + 60)
#define ANIM_TAG_061 (ANIM_SPRITES_START + 61)
#define ANIM_TAG_062 (ANIM_SPRITES_START + 62)
#define ANIM_TAG_063 (ANIM_SPRITES_START + 63)
#define ANIM_TAG_064 (ANIM_SPRITES_START + 64)
#define ANIM_TAG_065 (ANIM_SPRITES_START + 65)
#define ANIM_TAG_066 (ANIM_SPRITES_START + 66)
#define ANIM_TAG_067 (ANIM_SPRITES_START + 67)
#define ANIM_TAG_068 (ANIM_SPRITES_START + 68)
#define ANIM_TAG_069 (ANIM_SPRITES_START + 69)
#define ANIM_TAG_070 (ANIM_SPRITES_START + 70)
#define ANIM_TAG_071 (ANIM_SPRITES_START + 71)
#define ANIM_TAG_MUSIC_NOTES2 (ANIM_SPRITES_START + 72)
#define ANIM_TAG_DUCK (ANIM_SPRITES_START + 73)
#define ANIM_TAG_074 (ANIM_SPRITES_START + 74)
#define ANIM_TAG_075 (ANIM_SPRITES_START + 75)
#define ANIM_TAG_076 (ANIM_SPRITES_START + 76)
#define ANIM_TAG_077 (ANIM_SPRITES_START + 77)
#define ANIM_TAG_078 (ANIM_SPRITES_START + 78)
#define ANIM_TAG_079 (ANIM_SPRITES_START + 79)
#define ANIM_TAG_080 (ANIM_SPRITES_START + 80)
#define ANIM_TAG_081 (ANIM_SPRITES_START + 81)
#define ANIM_TAG_082 (ANIM_SPRITES_START + 82)
#define ANIM_TAG_083 (ANIM_SPRITES_START + 83)
#define ANIM_TAG_084 (ANIM_SPRITES_START + 84)
#define ANIM_TAG_085 (ANIM_SPRITES_START + 85)
#define ANIM_TAG_086 (ANIM_SPRITES_START + 86)
#define ANIM_TAG_ANGER (ANIM_SPRITES_START + 87)
#define ANIM_TAG_088 (ANIM_SPRITES_START + 88)
#define ANIM_TAG_089 (ANIM_SPRITES_START + 89)
#define ANIM_TAG_090 (ANIM_SPRITES_START + 90)
#define ANIM_TAG_091 (ANIM_SPRITES_START + 91)
#define ANIM_TAG_092 (ANIM_SPRITES_START + 92)
#define ANIM_TAG_093 (ANIM_SPRITES_START + 93)
#define ANIM_TAG_094 (ANIM_SPRITES_START + 94)
#define ANIM_TAG_095 (ANIM_SPRITES_START + 95)
#define ANIM_TAG_096 (ANIM_SPRITES_START + 96)
#define ANIM_TAG_BENT_SPOON (ANIM_SPRITES_START + 97)
#define ANIM_TAG_098 (ANIM_SPRITES_START + 98)
#define ANIM_TAG_MILK_BOTTLE (ANIM_SPRITES_START + 99)
#define ANIM_TAG_100 (ANIM_SPRITES_START + 100)
#define ANIM_TAG_101 (ANIM_SPRITES_START + 101)
#define ANIM_TAG_102 (ANIM_SPRITES_START + 102)
#define ANIM_TAG_103 (ANIM_SPRITES_START + 103)
#define ANIM_TAG_104 (ANIM_SPRITES_START + 104)
#define ANIM_TAG_105 (ANIM_SPRITES_START + 105)
#define ANIM_TAG_106 (ANIM_SPRITES_START + 106)
#define ANIM_TAG_107 (ANIM_SPRITES_START + 107)
#define ANIM_TAG_108 (ANIM_SPRITES_START + 108)
#define ANIM_TAG_109 (ANIM_SPRITES_START + 109)
#define ANIM_TAG_110 (ANIM_SPRITES_START + 110)
#define ANIM_TAG_111 (ANIM_SPRITES_START + 111)
#define ANIM_TAG_112 (ANIM_SPRITES_START + 112)
#define ANIM_TAG_113 (ANIM_SPRITES_START + 113)
#define ANIM_TAG_114 (ANIM_SPRITES_START + 114)
#define ANIM_TAG_115 (ANIM_SPRITES_START + 115)
#define ANIM_TAG_116 (ANIM_SPRITES_START + 116)
#define ANIM_TAG_117 (ANIM_SPRITES_START + 117)
#define ANIM_TAG_118 (ANIM_SPRITES_START + 118)
#define ANIM_TAG_119 (ANIM_SPRITES_START + 119)
#define ANIM_TAG_ITEM_BAG2 (ANIM_SPRITES_START + 120)
#define ANIM_TAG_121 (ANIM_SPRITES_START + 121)
#define ANIM_TAG_122 (ANIM_SPRITES_START + 122)
#define ANIM_TAG_123 (ANIM_SPRITES_START + 123)
#define ANIM_TAG_124 (ANIM_SPRITES_START + 124)
#define ANIM_TAG_125 (ANIM_SPRITES_START + 125)
#define ANIM_TAG_126 (ANIM_SPRITES_START + 126)
#define ANIM_TAG_127 (ANIM_SPRITES_START + 127)
#define ANIM_TAG_128 (ANIM_SPRITES_START + 128)
#define ANIM_TAG_129 (ANIM_SPRITES_START + 129)
#define ANIM_TAG_130 (ANIM_SPRITES_START + 130)
#define ANIM_TAG_131 (ANIM_SPRITES_START + 131)
#define ANIM_TAG_132 (ANIM_SPRITES_START + 132)
#define ANIM_TAG_133 (ANIM_SPRITES_START + 133)
#define ANIM_TAG_134 (ANIM_SPRITES_START + 134)
#define ANIM_TAG_135 (ANIM_SPRITES_START + 135)
#define ANIM_TAG_136 (ANIM_SPRITES_START + 136)
#define ANIM_TAG_137 (ANIM_SPRITES_START + 137)
#define ANIM_TAG_138 (ANIM_SPRITES_START + 138)
#define ANIM_TAG_139 (ANIM_SPRITES_START + 139)
#define ANIM_TAG_140 (ANIM_SPRITES_START + 140)
#define ANIM_TAG_141 (ANIM_SPRITES_START + 141)
#define ANIM_TAG_142 (ANIM_SPRITES_START + 142)
#define ANIM_TAG_143 (ANIM_SPRITES_START + 143)
#define ANIM_TAG_144 (ANIM_SPRITES_START + 144)
#define ANIM_TAG_145 (ANIM_SPRITES_START + 145)
#define ANIM_TAG_146 (ANIM_SPRITES_START + 146)
#define ANIM_TAG_147 (ANIM_SPRITES_START + 147)
#define ANIM_TAG_148 (ANIM_SPRITES_START + 148)
#define ANIM_TAG_149 (ANIM_SPRITES_START + 149)
#define ANIM_TAG_POISON_BUBBLE (ANIM_SPRITES_START + 150)
#define ANIM_TAG_TOXIC_BUBBLE (ANIM_SPRITES_START + 151)
#define ANIM_TAG_152 (ANIM_SPRITES_START + 152)
#define ANIM_TAG_153 (ANIM_SPRITES_START + 153)
#define ANIM_TAG_154 (ANIM_SPRITES_START + 154)
#define ANIM_TAG_155 (ANIM_SPRITES_START + 155)
#define ANIM_TAG_156 (ANIM_SPRITES_START + 156)
#define ANIM_TAG_157 (ANIM_SPRITES_START + 157)
#define ANIM_TAG_158 (ANIM_SPRITES_START + 158)
#define ANIM_TAG_159 (ANIM_SPRITES_START + 159)
#define ANIM_TAG_160 (ANIM_SPRITES_START + 160)
#define ANIM_TAG_161 (ANIM_SPRITES_START + 161)
#define ANIM_TAG_162 (ANIM_SPRITES_START + 162)
#define ANIM_TAG_163 (ANIM_SPRITES_START + 163)
#define ANIM_TAG_164 (ANIM_SPRITES_START + 164)
#define ANIM_TAG_165 (ANIM_SPRITES_START + 165)
#define ANIM_TAG_166 (ANIM_SPRITES_START + 166)
#define ANIM_TAG_167 (ANIM_SPRITES_START + 167)
#define ANIM_TAG_168 (ANIM_SPRITES_START + 168)
#define ANIM_TAG_169 (ANIM_SPRITES_START + 169)
#define ANIM_TAG_170 (ANIM_SPRITES_START + 170)
#define ANIM_TAG_171 (ANIM_SPRITES_START + 171)
#define ANIM_TAG_172 (ANIM_SPRITES_START + 172)
#define ANIM_TAG_173 (ANIM_SPRITES_START + 173)
#define ANIM_TAG_174 (ANIM_SPRITES_START + 174)
#define ANIM_TAG_175 (ANIM_SPRITES_START + 175)
#define ANIM_TAG_176 (ANIM_SPRITES_START + 176)
#define ANIM_TAG_177 (ANIM_SPRITES_START + 177)
#define ANIM_TAG_178 (ANIM_SPRITES_START + 178)
#define ANIM_TAG_179 (ANIM_SPRITES_START + 179)
#define ANIM_TAG_WEB_THREAD (ANIM_SPRITES_START + 180)
#define ANIM_TAG_SPIDER_WEB (ANIM_SPRITES_START + 181)
#define ANIM_TAG_182 (ANIM_SPRITES_START + 182)
#define ANIM_TAG_183 (ANIM_SPRITES_START + 183)
#define ANIM_TAG_184 (ANIM_SPRITES_START + 184)
#define ANIM_TAG_185 (ANIM_SPRITES_START + 185)
#define ANIM_TAG_186 (ANIM_SPRITES_START + 186)
#define ANIM_TAG_EYE (ANIM_SPRITES_START + 187)
#define ANIM_TAG_188 (ANIM_SPRITES_START + 188)
#define ANIM_TAG_189 (ANIM_SPRITES_START + 189)
#define ANIM_TAG_OPENING_EYE (ANIM_SPRITES_START + 190)
#define ANIM_TAG_191 (ANIM_SPRITES_START + 191)
#define ANIM_TAG_192 (ANIM_SPRITES_START + 192)
#define ANIM_TAG_193 (ANIM_SPRITES_START + 193)
#define ANIM_TAG_MOON (ANIM_SPRITES_START + 194)
#define ANIM_TAG_GREEN_SPARKLE (ANIM_SPRITES_START + 195)
#define ANIM_TAG_196 (ANIM_SPRITES_START + 196)
#define ANIM_TAG_197 (ANIM_SPRITES_START + 197)
#define ANIM_TAG_EXPLOSION (ANIM_SPRITES_START + 198)
#define ANIM_TAG_NAIL (ANIM_SPRITES_START + 199)
#define ANIM_TAG_200 (ANIM_SPRITES_START + 200)
#define ANIM_TAG_201 (ANIM_SPRITES_START + 201)
#define ANIM_TAG_BREAKING_EGG (ANIM_SPRITES_START + 202)
#define ANIM_TAG_203 (ANIM_SPRITES_START + 203)
#define ANIM_TAG_204 (ANIM_SPRITES_START + 204)
#define ANIM_TAG_BELL (ANIM_SPRITES_START + 205)
#define ANIM_TAG_MUSIC_NOTES (ANIM_SPRITES_START + 206)
#define ANIM_TAG_207 (ANIM_SPRITES_START + 207)
#define ANIM_TAG_208 (ANIM_SPRITES_START + 208)
#define ANIM_TAG_209 (ANIM_SPRITES_START + 209)
#define ANIM_TAG_PURPLE_HEART (ANIM_SPRITES_START + 210)
#define ANIM_TAG_211 (ANIM_SPRITES_START + 211)
#define ANIM_TAG_212 (ANIM_SPRITES_START + 212)
#define ANIM_TAG_213 (ANIM_SPRITES_START + 213)
#define ANIM_TAG_214 (ANIM_SPRITES_START + 214)
#define ANIM_TAG_215 (ANIM_SPRITES_START + 215)
#define ANIM_TAG_216 (ANIM_SPRITES_START + 216)
#define ANIM_TAG_217 (ANIM_SPRITES_START + 217)
#define ANIM_TAG_218 (ANIM_SPRITES_START + 218)
#define ANIM_TAG_219 (ANIM_SPRITES_START + 219)
#define ANIM_TAG_ANGEL (ANIM_SPRITES_START + 220)
#define ANIM_TAG_EVIL_ANGEL (ANIM_SPRITES_START + 221)
#define ANIM_TAG_222 (ANIM_SPRITES_START + 222)
#define ANIM_TAG_223 (ANIM_SPRITES_START + 223)
#define ANIM_TAG_ITEM_BAG (ANIM_SPRITES_START + 224)
#define ANIM_TAG_225 (ANIM_SPRITES_START + 225)
#define ANIM_TAG_226 (ANIM_SPRITES_START + 226)
#define ANIM_TAG_227 (ANIM_SPRITES_START + 227)
#define ANIM_TAG_LETTER_Z (ANIM_SPRITES_START + 228)
#define ANIM_TAG_229 (ANIM_SPRITES_START + 229)
#define ANIM_TAG_TRI_FORCE_TRIANGLE (ANIM_SPRITES_START + 230)
#define ANIM_TAG_231 (ANIM_SPRITES_START + 231)
#define ANIM_TAG_232 (ANIM_SPRITES_START + 232)
#define ANIM_TAG_233 (ANIM_SPRITES_START + 233)
#define ANIM_TAG_234 (ANIM_SPRITES_START + 234)
#define ANIM_TAG_235 (ANIM_SPRITES_START + 235)
#define ANIM_TAG_236 (ANIM_SPRITES_START + 236)
#define ANIM_TAG_237 (ANIM_SPRITES_START + 237)
#define ANIM_TAG_238 (ANIM_SPRITES_START + 238)
#define ANIM_TAG_239 (ANIM_SPRITES_START + 239)
#define ANIM_TAG_240 (ANIM_SPRITES_START + 240)
#define ANIM_TAG_GREEN_STAR (ANIM_SPRITES_START + 241)
#define ANIM_TAG_242 (ANIM_SPRITES_START + 242)
#define ANIM_TAG_243 (ANIM_SPRITES_START + 243)
#define ANIM_TAG_244 (ANIM_SPRITES_START + 244)
#define ANIM_TAG_245 (ANIM_SPRITES_START + 245)
#define ANIM_TAG_246 (ANIM_SPRITES_START + 246)
#define ANIM_TAG_HAND (ANIM_SPRITES_START + 247)
#define ANIM_TAG_248 (ANIM_SPRITES_START + 248)
#define ANIM_TAG_249 (ANIM_SPRITES_START + 249)
#define ANIM_TAG_X_SIGN (ANIM_SPRITES_START + 250)
#define ANIM_TAG_251 (ANIM_SPRITES_START + 251)
#define ANIM_TAG_252 (ANIM_SPRITES_START + 252)
#define ANIM_TAG_253 (ANIM_SPRITES_START + 253)
#define ANIM_TAG_254 (ANIM_SPRITES_START + 254)
#define ANIM_TAG_255 (ANIM_SPRITES_START + 255)
#define ANIM_TAG_256 (ANIM_SPRITES_START + 256)
#define ANIM_TAG_257 (ANIM_SPRITES_START + 257)
#define ANIM_TAG_MAGNIFYING_GLASS (ANIM_SPRITES_START + 258)
#define ANIM_TAG_259 (ANIM_SPRITES_START + 259)
#define ANIM_TAG_260 (ANIM_SPRITES_START + 260)
#define ANIM_TAG_261 (ANIM_SPRITES_START + 261)
#define ANIM_TAG_262 (ANIM_SPRITES_START + 262)
#define ANIM_TAG_263 (ANIM_SPRITES_START + 263)
#define ANIM_TAG_264 (ANIM_SPRITES_START + 264)
#define ANIM_TAG_265 (ANIM_SPRITES_START + 265)
#define ANIM_TAG_266 (ANIM_SPRITES_START + 266)
#define ANIM_TAG_267 (ANIM_SPRITES_START + 267)
#define ANIM_TAG_268 (ANIM_SPRITES_START + 268)
#define ANIM_TAG_269 (ANIM_SPRITES_START + 269)
#define ANIM_TAG_270 (ANIM_SPRITES_START + 270)
#define ANIM_TAG_271 (ANIM_SPRITES_START + 271)
#define ANIM_TAG_272 (ANIM_SPRITES_START + 272)
#define ANIM_TAG_273 (ANIM_SPRITES_START + 273)
#define ANIM_TAG_274 (ANIM_SPRITES_START + 274)
#define ANIM_TAG_275 (ANIM_SPRITES_START + 275)
#define ANIM_TAG_276 (ANIM_SPRITES_START + 276)
#define ANIM_TAG_277 (ANIM_SPRITES_START + 277)
#define ANIM_TAG_RECYCLE (ANIM_SPRITES_START + 278)
#define ANIM_TAG_279 (ANIM_SPRITES_START + 279)
#define ANIM_TAG_PROTECT (ANIM_SPRITES_START + 280)
#define ANIM_TAG_281 (ANIM_SPRITES_START + 281)
#define ANIM_TAG_282 (ANIM_SPRITES_START + 282)
#define ANIM_TAG_283 (ANIM_SPRITES_START + 283)
#define ANIM_TAG_284 (ANIM_SPRITES_START + 284)
#define ANIM_TAG_285 (ANIM_SPRITES_START + 285)
#define ANIM_TAG_286 (ANIM_SPRITES_START + 286)
#define ANIM_TAG_287 (ANIM_SPRITES_START + 287)
#define ANIM_TAG_288 (ANIM_SPRITES_START + 288)
#define ANIM_TAG_289 (ANIM_SPRITES_START + 289)
#define ANIM_TAG_290 (ANIM_SPRITES_START + 290)
#define ANIM_TAG_291 (ANIM_SPRITES_START + 291)
#define ANIM_TAG_292 (ANIM_SPRITES_START + 292)
#define ANIM_TAG_293 (ANIM_SPRITES_START + 293)
#define ANIM_TAG_294 (ANIM_SPRITES_START + 294)
#define ANIM_TAG_295 (ANIM_SPRITES_START + 295)
#define ANIM_TAG_296 (ANIM_SPRITES_START + 296)
#define ANIM_TAG_297 (ANIM_SPRITES_START + 297)
#define ANIM_TAG_298 (ANIM_SPRITES_START + 298)

// battlers
#define ANIM_ATTACKER 0
#define ANIM_TARGET 1
#define ANIM_ATK_PARTNER 2
#define ANIM_DEF_PARTNER 3

// stereo panning constants [0-255]
//
//          0
//         .  .
//      .        .
// 192 .          . 63
//     .          .
//      .        .
//         .  .
//          127
//  
#define SOUND_PAN_ATTACKER -64
#define SOUND_PAN_TARGET    63

// move background ids
#define BG_DARK_ 0 // the same as BG_DARK but is unused
#define BG_DARK 1
#define BG_GHOST 2
#define BG_PSYCHIC 3
#define BG_IMPACT_OPPONENT 4
#define BG_IMPACT_PLAYER 5
#define BG_IMPACT_CONTESTS 6
#define BG_DRILL 7
#define BG_DRILL_CONTESTS 8
#define BG_HIGHSPEED_OPPONENT 9
#define BG_HIGHSPEED_PLAYER 10
#define BG_THUNDER 11
#define BG_GUILLOTINE_OPPONENT 12
#define BG_GUILLOTINE_PLAYER 13
#define BG_GUILLOTINE_CONTESTS 14
#define BG_ICE 15
#define BG_COSMIC 16
#define BG_SEISMICTOSS_SKUUPPERCUT 17
#define BG_FLYING 18
#define BG_FLYING_CONTESTS 19
#define BG_AURORABEAM 20
#define BG_FISSURE 21
#define BG_BUG_OPPONENT 22
#define BG_BUG_PLAYER 23
#define BG_SOLARBEAM_OPPONENT 24
#define BG_SOLARBEAM_PLAYER 25
#define BG_SOLARBEAM_CONTESTS 26

// table ids for general animations
#define B_ANIM_CASTFORM_CHANGE          0x0
#define B_ANIM_STATS_CHANGE             0x1
#define B_ANIM_SUBSTITUTE_FADE          0x2
#define B_ANIM_SUBSTITUTE_APPEAR        0x3
#define B_ANIM_POKEBLOCK_THROW          0x4
#define B_ANIM_ITEM_KNOCKOFF            0x5
#define B_ANIM_TURN_TRAP                0x6
#define B_ANIM_ITEM_EFFECT              0x7
#define B_ANIM_SMOKEBALL_ESCAPE         0x8
#define B_ANIM_HANGED_ON                0x9
#define B_ANIM_RAIN_CONTINUES           0xA
#define B_ANIM_SUN_CONTINUES            0xB
#define B_ANIM_SANDSTORM_CONTINUES      0xC
#define B_ANIM_HAIL_CONTINUES           0xD
#define B_ANIM_LEECH_SEED_DRAIN         0xE
#define B_ANIM_MON_HIT                  0xF
#define B_ANIM_ITEM_STEAL               0x10
#define B_ANIM_SNATCH_MOVE              0x11
#define B_ANIM_FUTURE_SIGHT_HIT         0x12
#define B_ANIM_DOOM_DESIRE_HIT          0x13
#define B_ANIM_FOCUS_PUNCH_SETUP        0x14
#define B_ANIM_INGRAIN_HEAL             0x15
#define B_ANIM_WISH_HEAL                0x16

// special animations table
#define B_ANIM_LVL_UP                   0x0
#define B_ANIM_SWITCH_OUT_PLAYER_MON    0x1
#define B_ANIM_SWITCH_OUT_OPPONENT_MON  0x2
#define B_ANIM_BALL_THROW               0x3
#define B_ANIM_SAFARI_BALL_THROW        0x4
#define B_ANIM_SUBSTITUTE_TO_MON        0x5
#define B_ANIM_MON_TO_SUBSTITUTE        0x6

// status animation table
#define B_ANIM_STATUS_PSN               0x0
#define B_ANIM_STATUS_CONFUSION         0x1
#define B_ANIM_STATUS_BRN               0x2
#define B_ANIM_STATUS_INFATUATION       0x3
#define B_ANIM_STATUS_SLP               0x4
#define B_ANIM_STATUS_PRZ               0x5
#define B_ANIM_STATUS_FRZ               0x6
#define B_ANIM_STATUS_CURSED            0x7
#define B_ANIM_STATUS_NIGHTMARE         0x8
#define B_ANIM_STATUS_WRAPPED           0x9 // does not actually exist

// Most tasks return a value to gBattleAnimArgs[7].
#define ARG_RET_ID 0x7

// Trapping Wrap-like moves end turn animation.
#define TRAP_ANIM_BIND 0
#define TRAP_ANIM_WRAP 0
#define TRAP_ANIM_FIRE_SPIN 1
#define TRAP_ANIM_WHIRLPOOL 2
#define TRAP_ANIM_CLAMP 3
#define TRAP_ANIM_SAND_TOMB 4

// Weather defines for battle animation scripts.
#define ANIM_WEATHER_NONE 0
#define ANIM_WEATHER_SUN 1
#define ANIM_WEATHER_RAIN 2
#define ANIM_WEATHER_SANDSTORM 3
#define ANIM_WEATHER_HAIL 4

#endif // GUARD_CONSTANTS_BATTLE_ANIM_H
