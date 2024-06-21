/******************************************************************************
 *  Copyright (c) 2019, Xilinx, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1.  Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2.  Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *  3.  Neither the name of the copyright holder nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION). HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/
#define SIMD_in 2
#define SIMD_out 1
#define KERNEL_DIM 2
#define IFM_Channels 2
#define IFMDim 6
#define OFMDim 3
#define STRIDE 2
#define INPUT_PRECISION 8
#define MMV 1
#define INPUT_MULTIPLIER 1

// new parameters

namespace PARAM{
	// For default parameters the matrix is 8 x 9 in size
	// 		Where the 8 comes from: KERNEL_DIM * KERNEL_DIM * IFM_Channels / SIMD
	// 		And 9 comes from: OFMDim * OFMDim
	// So we need 8 booleans for the default parameters
	static const bool ColsToPrune[8]={
			false,
			true,
			false,
			false,
			true,
			true,
			false,
			false,
	};
    // For default parameters the matrix is 8 x 9 in size
    // 		Where the 8 comes from: KERNEL_DIM * KERNEL_DIM * IFM_Channels / SIMD_in
    //          With: KERNEL_DIM=2, IFM_Channels=2, SIMD_in=1
    //      Where the 1 comes from: SIMD_in
    //          With: SIMD_in=1
    // In this special case all values must be true, because no actual pruning takes place for SIMD_in=SIMD_out=1
    /*static bool SIMD_pruning_mask[8][1] = {
            {true},
            {true},
            {true},
            {true},
            {true},
            {true},
            {true},
            {true},
    };*/
	// New default parameters, true and false can be set somewhat randomly,
	// but there needs to be one true and one false per line
	static const bool SIMD_pruning_mask[4][2] = {
	            {true, false},
	            {false, true},
	            {true, false},
	            {true, false},
	};
}


