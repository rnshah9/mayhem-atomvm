/***************************************************************************
 *   Copyright 2017 by Davide Bettio <davide@uninstall.it>                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "atomshashtable.h"
#include "utils.h"

int main(int argc, char **argv)
{
    UNUSED(argc);
    UNUSED(argv);

    char atom_hello[] = {5, 'h', 'e', 'l', 'l', 'o'};
    char atom_ciao[] = {4, 'c', 'i', 'a', 'o'};
    char atom_a[] = {1, 'a'};
    char atom_b[] = {1, 'b'};
    char atom_c[] = {1, 'c'};
    char atom_d[] = {1, 'd'};
    char atom_e[] = {1, 'e'};
    char atom_f[] = {1, 'f'};
    char atom_0[] = {1, '0'};
    char atom_1[] = {1, '1'};
    char atom_2[] = {1, '2'};
    char atom_3[] = {1, '3'};
    char atom_4[] = {1, '4'};
    char atom_5[] = {1, '5'};
    char atom_6[] = {1, '6'};
    char atom_7[] = {1, '7'};
    char atom_8[] = {1, '8'};
    char atom_9[] = {1, '9'};

    struct AtomsHashTable *htable = atomshashtable_new();

    assert(atomshashtable_insert(htable, atom_hello, 0xABCD1234) == 1);
    assert(atomshashtable_get_value(htable, atom_hello, 0xCAFECAFE) == 0xABCD1234);
    assert(atomshashtable_get_value(htable, atom_ciao, 0xCAFECAFE) == 0xCAFECAFE);
    assert(atomshashtable_has_key(htable, atom_hello) == 1);
    assert(atomshashtable_has_key(htable, atom_ciao) == 0);

    assert(atomshashtable_insert(htable, atom_hello, 0x11112222) == 1);
    assert(atomshashtable_get_value(htable, atom_hello, 0xCAFECAFE) == 0x11112222);
    assert(atomshashtable_get_value(htable, atom_ciao, 0xCAFECAFE) == 0xCAFECAFE);

    assert(atomshashtable_insert(htable, atom_ciao, 0x99887766) == 1);
    assert(atomshashtable_get_value(htable, atom_ciao, 0xCAFECAFE) == 0x99887766);
    assert(atomshashtable_get_value(htable, atom_hello, 0xCAFECAFE) == 0x11112222);

    assert(atomshashtable_insert(htable, atom_a, 0xA) == 1);
    assert(atomshashtable_insert(htable, atom_b, 0xB) == 1);
    assert(atomshashtable_insert(htable, atom_c, 0xC) == 1);
    assert(atomshashtable_insert(htable, atom_d, 0xD) == 1);
    assert(atomshashtable_insert(htable, atom_e, 0xE) == 1);
    assert(atomshashtable_insert(htable, atom_f, 0xF) == 1);
    assert(atomshashtable_insert(htable, atom_0, 0x0) == 1);
    assert(atomshashtable_insert(htable, atom_1, 0x1) == 1);
    assert(atomshashtable_insert(htable, atom_2, 0x2) == 1);
    assert(atomshashtable_insert(htable, atom_3, 0x3) == 1);
    assert(atomshashtable_insert(htable, atom_4, 0x4) == 1);
    assert(atomshashtable_insert(htable, atom_5, 0x5) == 1);
    assert(atomshashtable_insert(htable, atom_6, 0x6) == 1);
    assert(atomshashtable_insert(htable, atom_7, 0x7) == 1);
    assert(atomshashtable_insert(htable, atom_8, 0x8) == 1);
    assert(atomshashtable_insert(htable, atom_9, 0x9) == 1);

    assert(atomshashtable_get_value(htable, atom_hello, 0xCAFECAFE) == 0x11112222);
    assert(atomshashtable_get_value(htable, atom_ciao, 0xCAFECAFE) == 0x99887766);
    assert(atomshashtable_get_value(htable, atom_a, 0xCAFEBABE) == 0xA);
    assert(atomshashtable_get_value(htable, atom_b, 0xCAFEBABE) == 0xB);
    assert(atomshashtable_get_value(htable, atom_c, 0xCAFEBABE) == 0xC);
    assert(atomshashtable_get_value(htable, atom_d, 0xCAFEBABE) == 0xD);
    assert(atomshashtable_get_value(htable, atom_e, 0xCAFEBABE) == 0xE);
    assert(atomshashtable_get_value(htable, atom_f, 0xCAFEBABE) == 0xF);
    assert(atomshashtable_get_value(htable, atom_0, 0xCAFEBABE) == 0x0);
    assert(atomshashtable_get_value(htable, atom_1, 0xCAFEBABE) == 0x1);
    assert(atomshashtable_get_value(htable, atom_2, 0xCAFEBABE) == 0x2);
    assert(atomshashtable_get_value(htable, atom_3, 0xCAFEBABE) == 0x3);
    assert(atomshashtable_get_value(htable, atom_4, 0xCAFEBABE) == 0x4);
    assert(atomshashtable_get_value(htable, atom_5, 0xCAFEBABE) == 0x5);
    assert(atomshashtable_get_value(htable, atom_6, 0xCAFEBABE) == 0x6);
    assert(atomshashtable_get_value(htable, atom_7, 0xCAFEBABE) == 0x7);
    assert(atomshashtable_get_value(htable, atom_8, 0xCAFEBABE) == 0x8);
    assert(atomshashtable_get_value(htable, atom_9, 0xCAFEBABE) == 0x9);

    assert(atomshashtable_has_key(htable, atom_hello) == 1);
    assert(atomshashtable_has_key(htable, atom_ciao) == 1);
    assert(atomshashtable_has_key(htable, atom_a) == 1);
    assert(atomshashtable_has_key(htable, atom_b) == 1);
    assert(atomshashtable_has_key(htable, atom_c) == 1);
    assert(atomshashtable_has_key(htable, atom_d) == 1);
    assert(atomshashtable_has_key(htable, atom_e) == 1);
    assert(atomshashtable_has_key(htable, atom_f) == 1);
    assert(atomshashtable_has_key(htable, atom_0) == 1);
    assert(atomshashtable_has_key(htable, atom_1) == 1);
    assert(atomshashtable_has_key(htable, atom_2) == 1);
    assert(atomshashtable_has_key(htable, atom_3) == 1);
    assert(atomshashtable_has_key(htable, atom_4) == 1);
    assert(atomshashtable_has_key(htable, atom_5) == 1);
    assert(atomshashtable_has_key(htable, atom_6) == 1);
    assert(atomshashtable_has_key(htable, atom_7) == 1);
    assert(atomshashtable_has_key(htable, atom_8) == 1);
    assert(atomshashtable_has_key(htable, atom_9) == 1);

    return EXIT_SUCCESS;
}
