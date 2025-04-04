// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueOroFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueOroFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueOro();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueOroFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueOroFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueOroFuncional
void ABloqueOroFuncional::StaticRegisterNativesABloqueOroFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueOroFuncional);
UClass* Z_Construct_UClass_ABloqueOroFuncional_NoRegister()
{
	return ABloqueOroFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueOroFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueOroFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueOroFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueOroFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueOroFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueOro,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueOroFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueOroFuncional_Statics::ClassParams = {
	&ABloqueOroFuncional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueOroFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueOroFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueOroFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueOroFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueOroFuncional.OuterSingleton, Z_Construct_UClass_ABloqueOroFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueOroFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueOroFuncional>()
{
	return ABloqueOroFuncional::StaticClass();
}
ABloqueOroFuncional::ABloqueOroFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueOroFuncional);
ABloqueOroFuncional::~ABloqueOroFuncional() {}
// End Class ABloqueOroFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueOroFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueOroFuncional, ABloqueOroFuncional::StaticClass, TEXT("ABloqueOroFuncional"), &Z_Registration_Info_UClass_ABloqueOroFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueOroFuncional), 4284126165U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueOroFuncional_h_2177918742(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueOroFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueOroFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
