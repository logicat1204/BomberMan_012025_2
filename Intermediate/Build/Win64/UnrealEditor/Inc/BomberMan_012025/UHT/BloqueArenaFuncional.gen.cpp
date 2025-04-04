// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueArenaFuncional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueArenaFuncional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueArena();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueArenaFuncional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueArenaFuncional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueArenaFuncional
void ABloqueArenaFuncional::StaticRegisterNativesABloqueArenaFuncional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueArenaFuncional);
UClass* Z_Construct_UClass_ABloqueArenaFuncional_NoRegister()
{
	return ABloqueArenaFuncional::StaticClass();
}
struct Z_Construct_UClass_ABloqueArenaFuncional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueArenaFuncional.h" },
		{ "ModuleRelativePath", "Public/BloqueArenaFuncional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueArenaFuncional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueArenaFuncional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueArena,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueArenaFuncional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueArenaFuncional_Statics::ClassParams = {
	&ABloqueArenaFuncional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueArenaFuncional_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueArenaFuncional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueArenaFuncional()
{
	if (!Z_Registration_Info_UClass_ABloqueArenaFuncional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueArenaFuncional.OuterSingleton, Z_Construct_UClass_ABloqueArenaFuncional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueArenaFuncional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueArenaFuncional>()
{
	return ABloqueArenaFuncional::StaticClass();
}
ABloqueArenaFuncional::ABloqueArenaFuncional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueArenaFuncional);
ABloqueArenaFuncional::~ABloqueArenaFuncional() {}
// End Class ABloqueArenaFuncional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueArenaFuncional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueArenaFuncional, ABloqueArenaFuncional::StaticClass, TEXT("ABloqueArenaFuncional"), &Z_Registration_Info_UClass_ABloqueArenaFuncional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueArenaFuncional), 2160337472U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueArenaFuncional_h_3273845654(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueArenaFuncional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueArenaFuncional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
