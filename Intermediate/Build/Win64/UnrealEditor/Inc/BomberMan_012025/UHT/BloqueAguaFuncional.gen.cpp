// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueAguaFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueAguaFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAgua();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAguaFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAguaFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueAguaFuncional
void ABloqueAguaFuncional::StaticRegisterNativesABloqueAguaFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueAguaFuncional);
UClass* Z_Construct_UClass_ABloqueAguaFuncional_NoRegister()
{
	return ABloqueAguaFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueAguaFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueAguaFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueAguaFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueAguaFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueAguaFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueAgua,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAguaFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueAguaFuncional_Statics::ClassParams = {
	&ABloqueAguaFuncional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAguaFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueAguaFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueAguaFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueAguaFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueAguaFuncional.OuterSingleton, Z_Construct_UClass_ABloqueAguaFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueAguaFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueAguaFuncional>()
{
	return ABloqueAguaFuncional::StaticClass();
}
ABloqueAguaFuncional::ABloqueAguaFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueAguaFuncional);
ABloqueAguaFuncional::~ABloqueAguaFuncional() {}
// End Class ABloqueAguaFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAguaFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueAguaFuncional, ABloqueAguaFuncional::StaticClass, TEXT("ABloqueAguaFuncional"), &Z_Registration_Info_UClass_ABloqueAguaFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueAguaFuncional), 4291296562U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAguaFuncional_h_4109867117(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAguaFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAguaFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
