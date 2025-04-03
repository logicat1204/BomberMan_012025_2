// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/MyBloqueLadrillo2Funcional.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBloqueLadrillo2Funcional() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLadrillo2();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AMyBloqueLadrillo2Funcional();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AMyBloqueLadrillo2Funcional_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AMyBloqueLadrillo2Funcional
void AMyBloqueLadrillo2Funcional::StaticRegisterNativesAMyBloqueLadrillo2Funcional()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyBloqueLadrillo2Funcional);
UClass* Z_Construct_UClass_AMyBloqueLadrillo2Funcional_NoRegister()
{
	return AMyBloqueLadrillo2Funcional::StaticClass();
}
struct Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyBloqueLadrillo2Funcional.h" },
		{ "ModuleRelativePath", "Public/MyBloqueLadrillo2Funcional.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBloqueLadrillo2Funcional>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloqueLadrillo2,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::ClassParams = {
	&AMyBloqueLadrillo2Funcional::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyBloqueLadrillo2Funcional()
{
	if (!Z_Registration_Info_UClass_AMyBloqueLadrillo2Funcional.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyBloqueLadrillo2Funcional.OuterSingleton, Z_Construct_UClass_AMyBloqueLadrillo2Funcional_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyBloqueLadrillo2Funcional.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AMyBloqueLadrillo2Funcional>()
{
	return AMyBloqueLadrillo2Funcional::StaticClass();
}
AMyBloqueLadrillo2Funcional::AMyBloqueLadrillo2Funcional() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyBloqueLadrillo2Funcional);
AMyBloqueLadrillo2Funcional::~AMyBloqueLadrillo2Funcional() {}
// End Class AMyBloqueLadrillo2Funcional

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_MyBloqueLadrillo2Funcional_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyBloqueLadrillo2Funcional, AMyBloqueLadrillo2Funcional::StaticClass, TEXT("AMyBloqueLadrillo2Funcional"), &Z_Registration_Info_UClass_AMyBloqueLadrillo2Funcional, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyBloqueLadrillo2Funcional), 4204513694U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_MyBloqueLadrillo2Funcional_h_721652770(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_MyBloqueLadrillo2Funcional_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_MyBloqueLadrillo2Funcional_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
