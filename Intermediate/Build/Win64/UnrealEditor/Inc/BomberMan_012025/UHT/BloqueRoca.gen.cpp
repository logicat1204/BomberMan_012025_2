// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueRoca.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueRoca() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueRoca();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueRoca_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueRoca
void ABloqueRoca::StaticRegisterNativesABloqueRoca()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueRoca);
UClass* Z_Construct_UClass_ABloqueRoca_NoRegister()
{
	return ABloqueRoca::StaticClass();
}
struct Z_Construct_UClass_ABloqueRoca_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueRoca.h" },
		{ "ModuleRelativePath", "Public/BloqueRoca.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueRoca>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueRoca_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueRoca_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueRoca_Statics::ClassParams = {
	&ABloqueRoca::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueRoca_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueRoca_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueRoca()
{
	if (!Z_Registration_Info_UClass_ABloqueRoca.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueRoca.OuterSingleton, Z_Construct_UClass_ABloqueRoca_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueRoca.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueRoca>()
{
	return ABloqueRoca::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueRoca);
ABloqueRoca::~ABloqueRoca() {}
// End Class ABloqueRoca

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRoca_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueRoca, ABloqueRoca::StaticClass, TEXT("ABloqueRoca"), &Z_Registration_Info_UClass_ABloqueRoca, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueRoca), 3716890365U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRoca_h_1511360174(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRoca_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueRoca_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
