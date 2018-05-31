/*
 * Copyright (c) 2008-2011 Zhang Ming (M. Zhang), zmjerry@163.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 2 or any later version.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details. A copy of the GNU General Public License is available at:
 * http://www.fsf.org/licensing/licenses
 */


/*****************************************************************************
 *                            filtercoefs-impl.h
 *
 * Implementation for filter coeffcients in wavelet transform.
 *
 * Zhang Ming, 2010-03, Xi'an Jiaotong University.
 *****************************************************************************/


/**
 * Daubichies filters for wavelets with 4 vanishing moments.
 */
template <typename Type>
void db4Coefs( Vector<Type> &ld, Vector<Type> &hd,
               Vector<Type> &lr, Vector<Type> &hr )
{
    ld.resize(8);
    ld[0] = Type(-0.010597401784997);		ld[1] = Type(0.032883011666983);
    ld[2] = Type(0.030841381835987); 		ld[3] = Type(-0.187034811718881);
    ld[4] = Type(-0.027983769416984);		ld[5] = Type(0.630880767929590);
    ld[6] = Type(0.714846570552542);		ld[7] = Type(0.230377813308855);

    hd.resize(8);
    hd[0] = Type(-0.230377813308855);		hd[1] = Type(0.714846570552542);
    hd[2] = Type(-0.630880767929590);		hd[3] = Type(-0.027983769416984);
    hd[4] = Type(0.187034811718881);		hd[5] = Type(0.030841381835987);
    hd[6] = Type(-0.032883011666983);		hd[7] = Type(-0.010597401784997);

    lr = flip(ld);
    hr = flip(hd);
}

/**
 * Daubichies filters for wavelets with 6 vanishing moments.
 */
template <typename Type>
void db6Coefs( Vector<Type> &ld, Vector<Type> &hd,
               Vector<Type> &lr, Vector<Type> &hr )
{
    hd.resize(12);
    hd[0] = Type(-0.111540743350080);		hd[1] = Type(0.494623890398385);
    hd[2] = Type(-0.751133908021578); 		hd[3] = Type(0.315250351709243);
    hd[4] = Type(0.226264693965169);		hd[5] = Type(-0.129766867567096);
    hd[6] = Type(-0.0975016055870794);		hd[7] = Type(0.0275228655300163);
    hd[8] = Type(0.0315820393180312);		hd[9] = Type(0.000553842200993802);
    hd[10] = Type(-0.00477725751101065);	hd[11] = Type(-0.00107730108499558);

    ld.resize(12);
    ld[0] = Type(-0.00107730108499558);		ld[1] = Type(0.00477725751101065);
    ld[2] = Type(0.000553842200993802);		ld[3] = Type(-0.0315820393180312);
    ld[4] = Type(0.0275228655300163);		ld[5] = Type(0.0975016055870794);
    ld[6] = Type(-0.129766867567096);		ld[7] = Type(-0.226264693965169);
    ld[8] = Type(0.315250351709243);		ld[9] = Type(0.751133908021578);
    ld[10] = Type(0.494623890398385);		ld[11] = Type(0.111540743350080);

    lr = flip(ld);
    hr = flip(hd);
}