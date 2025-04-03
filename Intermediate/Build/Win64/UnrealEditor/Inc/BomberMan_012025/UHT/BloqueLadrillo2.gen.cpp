// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/BloqueLadrillo2.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueLadrillo2() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLadrillo2();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLadrillo2_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueLadrillo2
void ABloqueLadrillo2::StaticRegisterNativesABloqueLadrillo2()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueLadrillo2);
UClass* Z_Construct_UClass_ABloqueLadrillo2_NoRegister()
{
	return ABloqueLadrillo2::StaticClass();
}
struct Z_Construct_UClass_ABloqueLadrillo2_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueLadrillo2.h" },
		{ "ModuleRelativePath", "Public/BloqueLadrillo2.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueLadrillo2>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueLadrillo2_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo2_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueLadrillo2_Statics::ClassParams = {
	&ABloqueLadrillo2::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo2_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueLadrillo2_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueLadrillo2()
{
	if (!Z_Registration_Info_UClass_ABloqueLadrillo2.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueLadrillo2.OuterSingleton, Z_Construct_UClass_ABloqueLadrillo2_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueLadrillo2.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueLadrillo2>()
{
	return ABloqueLadrillo2::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueLadrillo2);
ABloqueLadrillo2::~ABloqueLadrillo2() {}
// End Class ABloqueLadrillo2

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueLadrillo2_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueLadrillo2, ABloqueLadrillo2::StaticClass, TEXT("ABloqueLadrillo2"), &Z_Registration_Info_UClass_ABloqueLadrillo2, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueLadrillo2), 3554045108U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueLadrillo2_h_540737316(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueLadrillo2_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_BloqueLadrillo2_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
