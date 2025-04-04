// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/EnemigoSubterraneo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoSubterraneo() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoSubterraneo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoSubterraneo_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoSubterraneo
void AEnemigoSubterraneo::StaticRegisterNativesAEnemigoSubterraneo()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoSubterraneo);
UClass* Z_Construct_UClass_AEnemigoSubterraneo_NoRegister()
{
	return AEnemigoSubterraneo::StaticClass();
}
struct Z_Construct_UClass_AEnemigoSubterraneo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoSubterraneo.h" },
		{ "ModuleRelativePath", "Public/EnemigoSubterraneo.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoSubterraneo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEnemigoSubterraneo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoSubterraneo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoSubterraneo_Statics::ClassParams = {
	&AEnemigoSubterraneo::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoSubterraneo_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoSubterraneo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoSubterraneo()
{
	if (!Z_Registration_Info_UClass_AEnemigoSubterraneo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoSubterraneo.OuterSingleton, Z_Construct_UClass_AEnemigoSubterraneo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoSubterraneo.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoSubterraneo>()
{
	return AEnemigoSubterraneo::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoSubterraneo);
AEnemigoSubterraneo::~AEnemigoSubterraneo() {}
// End Class AEnemigoSubterraneo

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_EnemigoSubterraneo_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoSubterraneo, AEnemigoSubterraneo::StaticClass, TEXT("AEnemigoSubterraneo"), &Z_Registration_Info_UClass_AEnemigoSubterraneo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoSubterraneo), 2125045252U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_EnemigoSubterraneo_h_2400280174(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_EnemigoSubterraneo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_EnemigoSubterraneo_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
