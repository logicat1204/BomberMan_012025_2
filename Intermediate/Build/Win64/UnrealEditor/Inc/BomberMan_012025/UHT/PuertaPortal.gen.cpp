// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/PrimerParcial/PuertaPortal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePuertaPortal() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APuertaPortal();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APuertaPortal_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class APuertaPortal
void APuertaPortal::StaticRegisterNativesAPuertaPortal()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APuertaPortal);
UClass* Z_Construct_UClass_APuertaPortal_NoRegister()
{
	return APuertaPortal::StaticClass();
}
struct Z_Construct_UClass_APuertaPortal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PrimerParcial/PuertaPortal.h" },
		{ "ModuleRelativePath", "Public/PrimerParcial/PuertaPortal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "PuertaPortal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PrimerParcial/PuertaPortal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxCollision_MetaData[] = {
		{ "Category", "PuertaPortal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PrimerParcial/PuertaPortal.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoxCollision;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APuertaPortal>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APuertaPortal_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APuertaPortal, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APuertaPortal_Statics::NewProp_BoxCollision = { "BoxCollision", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APuertaPortal, BoxCollision), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxCollision_MetaData), NewProp_BoxCollision_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APuertaPortal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APuertaPortal_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APuertaPortal_Statics::NewProp_BoxCollision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APuertaPortal_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APuertaPortal_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APuertaPortal_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APuertaPortal_Statics::ClassParams = {
	&APuertaPortal::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APuertaPortal_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APuertaPortal_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APuertaPortal_Statics::Class_MetaDataParams), Z_Construct_UClass_APuertaPortal_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APuertaPortal()
{
	if (!Z_Registration_Info_UClass_APuertaPortal.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APuertaPortal.OuterSingleton, Z_Construct_UClass_APuertaPortal_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APuertaPortal.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<APuertaPortal>()
{
	return APuertaPortal::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APuertaPortal);
APuertaPortal::~APuertaPortal() {}
// End Class APuertaPortal

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PrimerParcial_PuertaPortal_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APuertaPortal, APuertaPortal::StaticClass, TEXT("APuertaPortal"), &Z_Registration_Info_UClass_APuertaPortal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APuertaPortal), 1361699180U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PrimerParcial_PuertaPortal_h_3550022813(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PrimerParcial_PuertaPortal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_PrimerParcial_PuertaPortal_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
