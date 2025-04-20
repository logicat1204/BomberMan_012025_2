// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/PlayerControllerPrueba.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerControllerPrueba() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APlayerControllerPrueba();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APlayerControllerPrueba_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class APlayerControllerPrueba
void APlayerControllerPrueba::StaticRegisterNativesAPlayerControllerPrueba()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerControllerPrueba);
UClass* Z_Construct_UClass_APlayerControllerPrueba_NoRegister()
{
	return APlayerControllerPrueba::StaticClass();
}
struct Z_Construct_UClass_APlayerControllerPrueba_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PlayerControllerPrueba.h" },
		{ "ModuleRelativePath", "Public/PlayerControllerPrueba.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerControllerPrueba>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APlayerControllerPrueba_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerControllerPrueba_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerControllerPrueba_Statics::ClassParams = {
	&APlayerControllerPrueba::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerControllerPrueba_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayerControllerPrueba_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlayerControllerPrueba()
{
	if (!Z_Registration_Info_UClass_APlayerControllerPrueba.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerControllerPrueba.OuterSingleton, Z_Construct_UClass_APlayerControllerPrueba_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlayerControllerPrueba.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<APlayerControllerPrueba>()
{
	return APlayerControllerPrueba::StaticClass();
}
APlayerControllerPrueba::APlayerControllerPrueba(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerControllerPrueba);
APlayerControllerPrueba::~APlayerControllerPrueba() {}
// End Class APlayerControllerPrueba

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PlayerControllerPrueba_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlayerControllerPrueba, APlayerControllerPrueba::StaticClass, TEXT("APlayerControllerPrueba"), &Z_Registration_Info_UClass_APlayerControllerPrueba, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerControllerPrueba), 296582794U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PlayerControllerPrueba_h_3460150335(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PlayerControllerPrueba_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PlayerControllerPrueba_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
