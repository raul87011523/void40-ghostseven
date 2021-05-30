/* Copyright 2020 GhostSeven
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

//Macros
enum custom_keycodes {
    M_OMAN = SAFE_RANGE,
    M_OMOD,
    M_OMODI,
    M_OMODT,
    M_OFBIN,
    M_OFBOOL,
    M_OFCHAR,
    M_OFDATE,
    M_OFTIME,
    M_OFFLOAT,
    M_OFHTML,
    M_OFINT,
    M_OFTXT,
    M_OFSEL,
    M_OFM2O,
    M_OFM2M,
    M_OFO2M,
    M_OMCREATE,
    M_OMWRITE,
    M_OMUNLINK,
    M_OMCOMP,
    M_OMCHANGE,
    M_OFORM,
    M_OFORMI,
    M_OTREE,
    M_OTREEI,
    M_OSEARCH,
    M_OSEARCHI,
    M_OGRAF,
    M_OGRAFI,
    M_OPIVOT,
    M_OPIVOTI,
    M_OKANBAN,
    M_OKANBANI,
    M_OCALENDAR,
    M_OCALENDARI,
    M_OGANTT,
    M_OGANTTI,
    M_OXPATH,
    M_OXPATHATTR,
    M_OACT,
    M_ONOTE,
    M_OPAGE,
    M_OMENUR,
    M_OMENUC,
    M_OMENUA,
    M_OCRON,
    M_OBTN,
    M_OBTNBOX,
    M_OFIELD,
    M_ODATA,
    M_OSTATUSBAR
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST,
  _NUMPAD,
  _MOV,
  _MS,
  _MSWH,
  _ODOOPY,
  _ODOOXML
};

#define SPCMS LT(_MOV, KC_SPC)

#define NUMPAD LT(_NUMPAD, KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RALT | LCtrl| LAlt | LGUI | Lower| Space| Space| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,  KC_Y,  KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,  KC_H,  KC_J,       KC_K,    KC_L,    KC_SCLN, NUMPAD,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,  KC_N,  KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_RALT,   KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), SPCMS, SPCMS, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |ODDOPY|ODDOPY|      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR,     KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_UNDS,     KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,      KC_F12,  S(KC_NUHS),  S(KC_NUBS),  KC_HOME, KC_END,  KC_ENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ODOOPY), MO(_ODOOPY), KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5   |   6   |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------+-------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5   |  F6   |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+-------+-------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11  |  F12  |ISO # |ISO / |Pg Up |Pg Dn | Enter|
 * |------+------+------+------+------+-------+-------+------+------+------+------+------|
 * |      |      |      |      |      |ODOOXML|ODOOXML|      | Prev | Vol- | Vol+ | Next |
 * `-------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, 
    KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,       KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_ENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ODOOXML), MO(_ODOOXML), KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust
 * ,----------------------------------------------------------------------------------.
 * |RESET |      |     |      |      |      |      |      |  7   |  8   |  9   | DEL  |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |      |      |     |      |      |      |      |      |  4   |  5   |  6   |      |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |      |      |     |      |      |      |      |      |  1   |  2   |  3   |      |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |EEPROM|      |     |      |      |      |      |      |      |   0  |      |      |
 * `----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    RESET,    KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_7,   KC_8,  KC_9,   KC_DEL,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_4,   KC_5,  KC_6,   KC_NO,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_1,   KC_2,  KC_3,   KC_NO,
    EEP_RST,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_0,  KC_NO,  KC_NO
),

/* NumPad
 * ,----------------------------------------------------------------------------------.
 * |      |      |     |      |      |      |      |      |  7   |  8   |  9   |      |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |      |      |     |      |      |      |      |      |  4   |  5   |  6   |      |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |      |      |     |      |      |      |      |      |  1   |  2   |  3   |      |
 * |------+------+-----+------+------+------+------+------+------+------+------+------|
 * |      |      |     |      |      |      |      |      |      |   0  |      |      |
 * `----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7,  KC_8, KC_9,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4,  KC_5, KC_6,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1,  KC_2, KC_3,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_NO, KC_NO
),

/* Move
 * ,---------------------------------------------------------------------------------------------------------------.
 * |      |         |         |         |          |         |         |         |         |         |      |      |
 * |------+---------+-------------------+----------+---------+---------+---------+-------------------+------+------|
 * |      |         |         |         |          |         | Left    | Down    |  Up     |Right    |      |      |
 * |------+---------+---------+---------+----------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         |          |         |         |         |         |         |      |      |
 * |------+---------+---------+---------+----------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         | MO(_MSWH)|  Space  |  Space  | MO(_MS) |         |         |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */
[_MOV] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, MO(_MS), KC_TRNS, KC_TRNS, MO(_MSWH), KC_NO, KC_NO,   KC_NO, KC_NO
),

/* Mouse Move
 * ,---------------------------------------------------------------------------------------------------------------.
 * |      |         |         |         |          |         |         |         |         |         |      |      |
 * |------+---------+-------------------+----------+---------+---------+---------+-------------------+------+------|
 * |      | KC_ACL0 | KC_ACL1 | KC_ACL2 | KC_BTN1  | KC_BTN2 | KC_MS_L | KC_MS_D | KC_MS_U | KC_MS_R |      |      |
 * |------+---------+---------+---------+----------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         |          |         |         |         |         |         |      |      |
 * |------+---------+---------+---------+----------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         | MO(_MSWH)|  Space  |  Space  |         |         |         |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */
[_MS] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1,   KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   MO(_MSWH), KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO
),

/* Mouse Wheel
 * ,--------------------------------------------------------------------------------------------------------------.
 * |      |         |         |         |         |         |         |         |         |         |      |      |
 * |------+---------+---------+---------+---------+---------+---------+---------+---------+---------+------+------|
 * |      | KC_ACL0 | KC_ACL1 | KC_ACL2 | KC_BTN1 | KC_BTN2 | KC_WH_L | KC_WH_D | KC_WH_U | KC_WH_R |      |      |
 * |------+---------+---------+---------+---------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         |         |         |         |         |         |         |      |      |
 * |------+---------+---------+---------+---------+---------+---------+---------+---------+---------+------+------|
 * |      |         |         |         |         |         |         |         |         |         |      |      |
 * `--------------------------------------------------------------------------------------------------------------'
 */
[_MSWH] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN1, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO
),

/* ODOO PY
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * |      | M_OMAN   | M_OMOD     | M_OMODI | M_OMODT  | M_OFBIN | M_OFBOOL | M_OFCHAR | M_OFDATE   | M_OFTIME  | M_OFFLOAT |      |
 * |------+----------+------------+---------+---------+---------+----------+----------+------------+-----------+------------+------|
 * |      | M_OFHTML | M_OFINT    | M_OFTXT | M_OFSEL | M_OFM2O | M_OFM2M  | M_OFO2M  | M_OMCREATE | M_OMWRITE | M_OMUNLINK |      |
 * |------+----------+------------+---------+---------+---------+----------+----------+------------+-----------+------------+------|
 * |      | M_OMCOMP | M_OMCHANGE |         |         |         |          |          |            |           |            |      |
 * |------+----------+------------+---------+---------+---------+----------+----------+------------+-----------+------------+------|
 * |      |          |            |         |         |         |          |          |            |           |            |      |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_ODOOPY] = LAYOUT_ortho_4x12(
    KC_NO, M_OMAN,   M_OMOD,     M_OMODI, M_OMODT, M_OFBIN, M_OFBOOL, M_OFCHAR, M_OFDATE,   M_OFTIME,  M_OFFLOAT,  KC_NO,
    KC_NO, M_OFHTML, M_OFINT,    M_OFTXT, M_OFSEL, M_OFM2O, M_OFM2M,  M_OFO2M,  M_OMCREATE, M_OMWRITE, M_OMUNLINK, KC_NO,
    KC_NO, M_OMCOMP, M_OMCHANGE, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,      KC_NO,
    KC_NO, KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_NO,     KC_NO,      KC_NO
),

/* OdooXML
 * ,--------------------------------------------------------------------------------------------------------------------------------------------------.
 * |      | M_OFORM   | M_OFORMI   | M_OTREE     | M_OTREEI     | M_OSEARCH | M_OSEARCHI | M_OXPATH   | M_OXPATHATTR | M_OACT   | M_ONOTE      |      |
 * |------+-----------+------------+-------------+--------------+-----------+------------+------------+--------------+----------+--------------+------|
 * |      | M_OPAGE   | M_OMENUR   | M_OMENUC    | M_OMENUA     | M_OCRON   | M_OBTN     | M_OBTNBOX  | M_OFIELD     | M_ODATA  | M_OSTATUSBAR |      |
 * |------+-----------+------------+-------------+--------------+-----------+------------+------------+--------------+----------+--------------+------|
 * |      | M_OGRAF   | M_OGRAFI   | M_OPIVOT    | M_OPIVOTI    | M_OKANBAN | M_OKANBANI | M_OCALENDAR| M_OCALENDARI | M_OGANTT | M_OGANTTI    |      |
 * |------+-----------+------------+-------------+--------------+-----------+------------+------------+--------------+----------+--------------+------|
 * |      |           |            |             |              |           |            |            |              |          |              |      |
 * `--------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_ODOOXML] = LAYOUT_ortho_4x12(
    KC_NO, M_OFORM, M_OFORMI, M_OTREE,  M_OTREEI,  M_OSEARCH, M_OSEARCHI, M_OXPATH,    M_OXPATHATTR, M_OACT,   M_ONOTE,      KC_NO,
    KC_NO, M_OPAGE, M_OMENUR, M_OMENUC, M_OMENUA,  M_OCRON,   M_OBTN,     M_OBTNBOX,   M_OFIELD,     M_ODATA,  M_OSTATUSBAR, KC_NO,
    KC_NO, M_OGRAF, M_OGRAFI, M_OPIVOT, M_OPIVOTI, M_OKANBAN, M_OKANBANI, M_OCALENDAR, M_OCALENDARI, M_OGANTT, M_OGANTTI,    KC_NO,
    KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO,      KC_NO,       KC_NO,        KC_NO,    KC_NO,        KC_NO
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    }
  }
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}


void matrix_init_user(void) {

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_OMAN:
        if (record->event.pressed) {
        	// when keycode M_OMAN is pressed
            SEND_STRING("{\n\t'name': '',\n'vesion': '',\n'summary': '',\n' category' : '',\n' author' : '',\n'maintainer': '',\n'website': '',\n'license': '',\n' contributors' : [\n\t'',\n\b],\n'depends': [\n\t'',\n\b],\n' external_dependencies' : {\n\t'python': [\n\t'',\n\b],\n\b},\n'data': [\n\t'',\n\b],\n' installable' : True,\n' auto_install' : False,\n' application' : False,\n\b}");
        }
     	else {
            // when keycode M_OMAN is released
            unregister_code(KC_LSHIFT);
            unregister_code(KC_N);
        }
        break;
    case M_OMOD:
        if (record->event.pressed) {
            SEND_STRING("from odoo import api, fields, models\n\nclass ModuleName(models.Model):\n\t_name = 'module.name'\n_description = 'New Description'\nname = fields.Char(string='Name')\n\n");
        }
        break;
    case M_OMODI:
        if (record->event.pressed) {
            SEND_STRING("from odoo import api, fields, models\n\nclass ModuleName(models.Model):\n\t_inherit = 'module.name'\nname = fields.Char(string='Name')\n\n");
        }
        break;
    case M_OMODT:
        if (record->event.pressed) {
            SEND_STRING("from odoo import api, fields, models\n\nclass TestModuleName(TransactionCase):\n\tdef setUp(self):\n\t\tsuper(TestModuleName, self).setUp()\n\n");
        }
        break;
    case M_OFBIN:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Binary(string='')\n");
        }
        break;
    case M_OFBOOL:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Boolean(string='')\n");
        }
        break;
    case M_OFCHAR:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Char(string='')\n");
        }
        break;
    case M_OFDATE:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Date(string='')\n");
        }
        break;
    case M_OFTIME:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Datetime(string='')\n");
        }
        break;
    case M_OFFLOAT:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Float(string='')\n");
        }
        break;
    case M_OFHTML:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.HTML(string='')\n");
        }
        break;
    case M_OFINT:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Integer(string='')\n");
        }
        break;
    case M_OFTXT:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Text(string='')\n");
        }
        break;
    case M_OFSEL:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Selection(string='', selection=[('', ''), ('', ''),])\n");
        }
        break;
    case M_OFM2O:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Many2one(comodel_name='', string='')\n");
        }
        break;
    case M_OFM2M:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.Many2many(comodel_name='', string='')\n");
        }
        break;
    case M_OFO2M:
        if (record->event.pressed) {
            SEND_STRING("new_field = fields.One2many(comodel_name='', inverse_name='', string='')\n");
        }
        break;
    case M_OMCREATE:
        if (record->event.pressed) {
            SEND_STRING("@api.model\ndef create(self, values):\n\t# Add code here\nreturn super(ClassName, self).create(values)\n\n\b");
        }
        break;
    case M_OMWRITE:
        if (record->event.pressed) {
            SEND_STRING("@api.multi\ndef write(self, values):\n\t# Add code here\nreturn super(ClassName, self).write(values)\n\n\b");
        }
        break;
    case M_OMUNLINK:
        if (record->event.pressed) {
            SEND_STRING("@api.multi\ndef unlink(self, values):\n\t# Add code here\nreturn super(ClassName, self).unlink(values)\n\n\b");
        }
        break;
    case M_OMCOMP:
        if (record->event.pressed) {
            SEND_STRING("@api.depends('field_name')\ndef _compute_field_name(self):\n\tself.field_name = ''\n\n\b");
        }
        break;
    case M_OMCHANGE:
        if (record->event.pressed) {
            SEND_STRING("@api.onchange('field_name')\ndef _onchange_field_name(self):\n\tself.field_name = ''\n\n\b");
        }
        break;

    case M_OFORM:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name form view -->\n<record id=\"model_name_view_form\"  model=\" ir.ui.view\" >\n\t <field name=\"name\">model.name.view.form</field>\n<field name=\"model\">model.name</field>\n<field name=\" arch\"  type=\"xml\">\n\t<form string=\"\">\n\t<sheet>\n\t<group>\n\t<!-- Add your fields here -->\n\b</group>\n\b</sheet>\n\b</form>\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OFORMI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit form view -->\n<record id=\"view_id\"  model=\" ir.ui.view\" >\n\t<field name=\"name\">model.name.inherit.view.form</field>\n<field name=\"model\">model.name</field>\n<field name=\" inherit_id\"  ref=\"base_module.view_id\"/>\n<field name=\" arch\"  type=\"xml\">\n\t<!-- Add your xpath here -->\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OTREE:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name tree view -->\n<record id=\"model_name_view_tree\"  model=\" ir.ui.view\" >\n\t<field name=\"name\">model.name.view.tree</field>\n<field name=\"model\">model.name</field>\n<field name=\" arch\"  type=\"xml\">\n\t<tree>\n\t<!-- Add your fields here -->\n\b</tree>\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OTREEI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit tree view -->\n<record id=\"view_id\"  model=\" ir.ui.view\" >\n\t<field name=\"name\">model.name.inherit.view.tree</field>\n<field name=\"model\">model.name</field>\n<field name=\" inherit_id\"  ref=\"base_module.view_id\"/>\n<field name=\" arch\"  type=\"xml\">\n\t<!-- Add your xpath here -->\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OSEARCH:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name search view -->\n<record id=\"model_name_view_search\"  model=\" ir.ui.view\" >\n\t<field name=\"name\">model.name.view.search</field>\n<field name=\"model\">model.name</field>\n<field name=\" arch\"  type=\"xml\">\n\t<search string=\"Search Description\">\n\t<!-- Add your fields here -->\n\b</search>\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OSEARCHI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit search view -->\n<record id=\"view_id\"  model=\" ir.ui.view\" >\n\t<field name=\"name\">model.name.inherit.view.search</field>\n<field name=\"model\">model.name</field>\n<field name=\" inherit_id\"  ref=\"base_module.view_id\"/>\n<field name=\" arch\"  type=\"xml\">\n\t<!-- Add your xpath here -->\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_OXPATH:
        if (record->event.pressed) {
            SEND_STRING("<xpath expr=\"//field[@name='name']\"  position=\" after\" >\n\t<!-- Add your fields here -->\n\b</xpath>\n");
        }
        break;
    case M_OXPATHATTR:
        if (record->event.pressed) {
            SEND_STRING("<xpath expr=\"//field[@name='name']\"  position=\" attributes\" >\n\t<attribute name=\" attrs\" >{}</attribute>\n\b</xpath>\n");
        }
        break;
    case M_OACT:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name action window -->\n<record id=\"model_name_action\"  model=\" ir.actions.act_window\" >\n\t<field name=\"name\">model.name.action</field>\n<field name=\"type\">ir.actions.act_window</field>\n<field name=\"res_model\">model.name</field>\n<field name=\"view_mode\">tree,form</field>\n<field name=\"view_type\">form</field>\n<field name=\"help\"  type=\"html\">\n\t<p class=\" oe_view_nocontent_create\" >\n\t<!-- Add Text Here -->\n\b</p>\n<p>\n\t<!-- More details about what a user can do with this object will be OK -->\n\b</p>\n\b</field>\n\b</record>\n\n");
        }
        break;
    case M_ONOTE:
        if (record->event.pressed) {
            SEND_STRING("<notebook>\n\t<page string=\" \"  name=\" \" >\n\t<group>\n\t<field name=\" \" />\n\b</group>\n\b</page>\n\b</notebook>\n");
        }
        break;
    case M_OPAGE:
        if (record->event.pressed) {
            SEND_STRING("<page string=\" \"  name=\" \" >\n\t<group>\n\t<field name=\" \" />\n\b</group>\n\b</page>\n");
        }
        break;
    case M_OMENUR:
        if (record->event.pressed) {
            SEND_STRING("<!-- This Menu Item will appear in the Upper bar, that's why It needs NO parent or action -->\n<menuitem id=\"_menu_root\"  name=\" \"  sequence=\" \" />\n\n");
        }
        break;
    case M_OMENUC:
        if (record->event.pressed) {
            SEND_STRING("<!-- This Menu Item Must have a parent -->\n<menuitem id=\"_menu_categ\"  name=\" \"  parent=\" \"  sequence=\" \" />\n\n");
        }
        break;
    case M_OMENUA:
        if (record->event.pressed) {
            SEND_STRING("<!-- This Menu Item must have a parent and an action -->\n<menuitem id=\"_menu_act\"  name=\" \"  parent=\" \"  action=\" \"  sequence=\" \" />\n\n");
        }
        break;
    case M_OCRON:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name cron -->\n<record id=\"model_name_ir_cron\"  forcecreate=\"True\"  model=\" ir.cron\" >\n\t<field name=\"name\">model.name.ir.cron</field>\n<field name=\" user_id\"  ref=\"base.user_root\"/>\n<field name=\"doall\"  eval=\"False\"/>\n<field name=\" active\"  eval=\"True\"/>\n<field name=\" interval_number\" >1</field>\n<field name=\" interval_type\" >minutes</field>\n<field name=\"numbercall\">-1</field>\n<field name=\"model_id\"  ref=\"model_model_name\"/>\n<field name=\"state\">code</field>\n<field name=\"code\">model.method_name()</field>\n\b</record>\n\n");
        }
        break;
    case M_OBTN:
        if (record->event.pressed) {
            SEND_STRING("<button name=\" action_button_method_name\"  type=\" object\"  string=\" ObjectButton\" />\n");
        }
        break;
    case M_OBTNBOX:
        if (record->event.pressed) {
            SEND_STRING("<div class=\" oe_button_box\"  name=\"model_name_button_box\">\n\t<button name=\" action_toggle_active\" \n\ttype=\" object\"  \nconfirm=\"(Un)archiving a project automatically (un)archives its tasks and issues. Do you want to proceed?\"\nclass=\" oe_stat_button\" \nicon=\"fa-archive\">\n<field name=\" active\"  widget=\"boolean_button\"  options='{\"terminology\": \" archive\" }'/>\n\b</button>\n\b</div>\n\n");
        }
        break;
    case M_OFIELD:
        if (record->event.pressed) {
            SEND_STRING("<field name='name'/>\n");
        }
        break;
    case M_ODATA:
        if (record->event.pressed) {
            SEND_STRING("<?xml version='1.0' encoding='utf-8'?>\n<odoo>\n\t<data noupdate=\"1\">\n\t<!-- Add you code here -->\n\b</data>\n\b</odoo>\n");
        }
        break;
    case M_OSTATUSBAR:
        if (record->event.pressed) {
            SEND_STRING("<header>\n\t<field name=\" \"  widget=\"statusbar\"/>\n\b</header>\n");
        }
        break;
    /*case M_OGRAF:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name graph view -->\n<record id=\"model_name_view_graph\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.view.graph</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<graph string=\"Graph Description\">\n\t\t\t<!-- Add your fields here -->\n\t\t</graph>\n\t</field>\n</record>");
        }
        break;
    case M_OGRAFI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit graph view -->\n<record id=\"view_id\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.inherit.view.graph</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"inherit_id\" ref=\"base_module.view_id\"/>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<!-- Add you xpath here -->\n\t</field>\n</record>");
        }
        break;
    case M_OPIVOT:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name pivot view -->\n<record id=\"model_name_view_pivot\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.view.pivot</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<pivot string=\"Pivot Description\">\n\t\t\t<!-- Add your fields here -->\n\t\t</pivot>\n\t</field>\n</record>");
        }
        break;
    case M_OPIVOTI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit pivot view -->\n<record id=\"view_id\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.inherit.view.pivot</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"inherit_id\" ref=\"base_module.view_id\"/>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<!-- Add you xpath here -->\n\t</field>\n</record>");
        }
        break;
    case M_OKANBAN:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name kanban view -->\n<record id=\"model_name_view_kanban\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.view.kanban</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<kanban string=\"Kanban Description\">\n\t\t\t<!-- Add your fields here -->\n\t\t</kanban>\n\t</field>\n</record>");
        }
        break;
    case M_OKANBANI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit kanban view -->\n<record id=\"view_id\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.inherit.view.kanban</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"inherit_id\" ref=\"base_module.view_id\"/>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<!-- Add you xpath here -->\n\t</field>\n</record>");
        }
        break;
    case M_OCALENDAR:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name calendar view -->\n<record id=\"model_name_view_calendar\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.view.calendar</field>\n\t<field name=\"model\">model.name</field>\n\t    <field name=\"arch\" type=\"xml\">\n\t\t<calendar string=\"Calendar Description\" date_start=\"{4}\" mode=\"{6:month}\">\n\t\t\t<!-- Add your fields here -->\n\t\t</calendar>\n\t</field>\n</record>");
        }
        break;
    case M_OCALENDARI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit calendar view -->\n<record id=\"view_id\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.inherit.view.calendar</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"inherit_id\" ref=\"base_module.view_id\"/>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<!-- Add you xpath here -->\n\t</field>\n</record>");
        }
        break;
    case M_OGANTT:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name gantt view -->\n<record id=\"model_name_view_gantt\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.view.gantt</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<gantt string=\"Gantt Description\" date_start=\"{4}\">\n\t\t\t<!-- Add your fields here -->\n\t\t</gantt>\n\t</field>\n</record>");
        }
        break;
    case M_OGANTTI:
        if (record->event.pressed) {
            SEND_STRING("<!-- model.name inherit gantt view -->\n<record id=\"view_id\" model=\"ir.ui.view\">\n\t<field name=\"name\">model.name.inherit.view.gantt</field>\n\t<field name=\"model\">model.name</field>\n\t<field name=\"inherit_id\" ref=\"base_module.view_id\"/>\n\t<field name=\"arch\" type=\"xml\">\n\t\t<!-- Add you xpath here -->\n\t</field>\n</record>");
        }
        break;*/
    }
    return true;
};
