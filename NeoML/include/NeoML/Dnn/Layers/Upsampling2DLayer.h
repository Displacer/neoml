﻿/* Copyright © 2017-2020 ABBYY Production LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
--------------------------------------------------------------------------------------------------------------*/

#pragma once

#include <NeoML/NeoMLDefs.h>
#include <NeoML/Dnn/Dnn.h>

namespace NeoML {

// The layer that scales up a set of two-dimensional multi-channel images. 
// The new pixels are filled up by repeating the existing pixels' values.
class NEOML_API CUpsampling2DLayer : public CBaseLayer {
	NEOML_DNN_LAYER( CUpsampling2DLayer )
public:
	explicit CUpsampling2DLayer( IMathEngine& mathEngine );

	virtual void Serialize( CArchive& archive ) override;

	int GetHeightCopyCount() const { return heightCopyCount; }
	void SetHeightCopyCount( int newHeightCopyCount );

	int GetWidthCopyCount() const { return widthCopyCount; }
	void SetWidthCopyCount( int newWidthCopyCount );

protected:
	virtual void Reshape() override;
	virtual void RunOnce() override;
	virtual void BackwardOnce() override;

private:
	// The number of vertical repetitions
	int heightCopyCount;
	// The number of horizontal repetitions
	int widthCopyCount;
};

} // namespace NeoML
