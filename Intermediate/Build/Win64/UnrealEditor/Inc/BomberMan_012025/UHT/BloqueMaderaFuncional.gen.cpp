// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueMaderaFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueMaderaFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMadera();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMaderaFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMaderaFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueMaderaFuncional
void ABloqueMaderaFuncional::StaticRegisterNativesABloqueMaderaFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueMaderaFuncional);
UClass* Z_Construct_UClass_ABloqueMaderaFuncional_NoRegister()
{
	return ABloqueMaderaFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueMaderaFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueMaderaFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueMaderaFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueMaderaFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueMaderaFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueMadera,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMaderaFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueMaderaFuncional_Statics::ClassParams = {
	&ABloqueMaderaFuncional::StaticClass,
	"Engine",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMaderaFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueMaderaFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueMaderaFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueMaderaFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueMaderaFuncional.OuterSingleton, Z_Construct_UClass_ABloqueMaderaFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueMaderaFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueMaderaFuncional>()
{
	return ABloqueMaderaFuncional::StaticClass();
}
ABloqueMaderaFuncional::ABloqueMaderaFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueMaderaFuncional);
ABloqueMaderaFuncional::~ABloqueMaderaFuncional() {}
// End Class ABloqueMaderaFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueMaderaFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueMaderaFuncional, ABloqueMaderaFuncional::StaticClass, TEXT("ABloqueMaderaFuncional"), &Z_Registration_Info_UClass_ABloqueMaderaFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueMaderaFuncional), 2109157918U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueMaderaFuncional_h_3599726465(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueMaderaFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueMaderaFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
