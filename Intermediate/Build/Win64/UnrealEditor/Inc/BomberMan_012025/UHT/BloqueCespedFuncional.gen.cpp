// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueCespedFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueCespedFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueCesped();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueCespedFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueCespedFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueCespedFuncional
void ABloqueCespedFuncional::StaticRegisterNativesABloqueCespedFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueCespedFuncional);
UClass* Z_Construct_UClass_ABloqueCespedFuncional_NoRegister()
{
	return ABloqueCespedFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueCespedFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueCespedFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueCespedFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueCespedFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueCespedFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueCesped,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCespedFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueCespedFuncional_Statics::ClassParams = {
	&ABloqueCespedFuncional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCespedFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueCespedFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueCespedFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueCespedFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueCespedFuncional.OuterSingleton, Z_Construct_UClass_ABloqueCespedFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueCespedFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueCespedFuncional>()
{
	return ABloqueCespedFuncional::StaticClass();
}
ABloqueCespedFuncional::ABloqueCespedFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueCespedFuncional);
ABloqueCespedFuncional::~ABloqueCespedFuncional() {}
// End Class ABloqueCespedFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueCespedFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueCespedFuncional, ABloqueCespedFuncional::StaticClass, TEXT("ABloqueCespedFuncional"), &Z_Registration_Info_UClass_ABloqueCespedFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueCespedFuncional), 4272138704U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueCespedFuncional_h_1118134974(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueCespedFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueCespedFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
