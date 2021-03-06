// VRM4U Copyright (c) 2021 Haruyoshi Yamamoto. This software is released under the MIT License.

#pragma once

#include "VrmImportUI.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Factories/ImportSettings.h"
#include "VrmConvert.h"

const FImportOptionData* UVrmImportUI::GenerateOptionData() {

	FImportOptionData &d = data;

#define c(a)  d.a = a;

	d.init();

	c(bAPoseRetarget);

	c(bMobileBone);

	c(MaterialType);

	c(ModelScale);

	c(bCreateHumanoidRenamedMesh);

	c(bCreateIKBone);

	c(bSkipPhysics);

	c(bSkipMorphTarget);

	c(bEnableMorphTargetNormal);

	c(bNoTranslucent);

	c(bSingleUAssetFile);

	c(bDefaultGridTextureMode);

	c(bBC7Mode);

	c(bMipmapGenerateMode);

	c(bMergeMaterial);

	c(bMergePrimitive);

	c(bOptimizeVertex);

	c(BoneWeightInfluenceNum);

	c(bSimpleRoot);

	c(bSkipNoMeshBone);

	c(bDebugOneBone);

	c(Skeleton);

	return &data;
}

