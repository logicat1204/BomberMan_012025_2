// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueAcero2.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueAcero2() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAcero2();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAcero2_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueAcero2
void ABloqueAcero2::StaticRegisterNativesABloqueAcero2()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueAcero2);
UClass* Z_Construct_UClass_ABloqueAcero2_NoRegister()
{
	return ABloqueAcero2::StaticClass();
}
struct Z_Construct_UClass_ABloqueAcero2_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueAcero2.h" },
		{ "ModuleRelativePath", "Public/BloqueAcero2.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueAcero2>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueAcero2_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero2_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueAcero2_Statics::ClassParams = {
	&ABloqueAcero2::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero2_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueAcero2_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueAcero2()
{
	if (!Z_Registration_Info_UClass_ABloqueAcero2.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueAcero2.OuterSingleton, Z_Construct_UClass_ABloqueAcero2_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueAcero2.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueAcero2>()
{
	return ABloqueAcero2::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueAcero2);
ABloqueAcero2::~ABloqueAcero2() {}
// End Class ABloqueAcero2

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAcero2_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueAcero2, ABloqueAcero2::StaticClass, TEXT("ABloqueAcero2"), &Z_Registration_Info_UClass_ABloqueAcero2, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueAcero2), 2912645650U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAcero2_h_2239541168(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAcero2_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueAcero2_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
