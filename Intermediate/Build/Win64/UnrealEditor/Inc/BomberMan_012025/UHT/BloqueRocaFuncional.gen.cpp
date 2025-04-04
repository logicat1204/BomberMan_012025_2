// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueRocaFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueRocaFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueRoca();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueRocaFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueRocaFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueRocaFuncional
void ABloqueRocaFuncional::StaticRegisterNativesABloqueRocaFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueRocaFuncional);
UClass* Z_Construct_UClass_ABloqueRocaFuncional_NoRegister()
{
	return ABloqueRocaFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueRocaFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueRocaFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueRocaFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueRocaFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueRocaFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueRoca,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueRocaFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueRocaFuncional_Statics::ClassParams = {
	&ABloqueRocaFuncional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueRocaFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueRocaFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueRocaFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueRocaFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueRocaFuncional.OuterSingleton, Z_Construct_UClass_ABloqueRocaFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueRocaFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueRocaFuncional>()
{
	return ABloqueRocaFuncional::StaticClass();
}
ABloqueRocaFuncional::ABloqueRocaFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueRocaFuncional);
ABloqueRocaFuncional::~ABloqueRocaFuncional() {}
// End Class ABloqueRocaFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRocaFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueRocaFuncional, ABloqueRocaFuncional::StaticClass, TEXT("ABloqueRocaFuncional"), &Z_Registration_Info_UClass_ABloqueRocaFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueRocaFuncional), 2865254809U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRocaFuncional_h_423565579(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRocaFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRocaFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
