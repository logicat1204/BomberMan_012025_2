// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Public/Prototypes/PrototypeEnemigo1.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototypeEnemigo1() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APrototypeEnemigo1();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_APrototypeEnemigo1_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class APrototypeEnemigo1
void APrototypeEnemigo1::StaticRegisterNativesAPrototypeEnemigo1()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APrototypeEnemigo1);
UClass* Z_Construct_UClass_APrototypeEnemigo1_NoRegister()
{
	return APrototypeEnemigo1::StaticClass();
}
struct Z_Construct_UClass_APrototypeEnemigo1_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Prototypes/PrototypeEnemigo1.h" },
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PuntoA_MetaData[] = {
		{ "Category", "Patrullaje" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Patrullar por un punto A y otro B\n" },
#endif
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Patrullar por un punto A y otro B" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PuntoB_MetaData[] = {
		{ "Category", "Patrullaje" },
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocidadMovimiento_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RangoVision_MetaData[] = {
		{ "Category", "Deteccion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Detectar y perseguir jugador\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detectar y perseguir jugador" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JugadorDetectado_MetaData[] = {
		{ "ModuleRelativePath", "Public/Prototypes/PrototypeEnemigo1.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PuntoA;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PuntoB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VelocidadMovimiento;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RangoVision;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JugadorDetectado;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototypeEnemigo1>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_PuntoA = { "PuntoA", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APrototypeEnemigo1, PuntoA), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PuntoA_MetaData), NewProp_PuntoA_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_PuntoB = { "PuntoB", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APrototypeEnemigo1, PuntoB), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PuntoB_MetaData), NewProp_PuntoB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_VelocidadMovimiento = { "VelocidadMovimiento", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APrototypeEnemigo1, VelocidadMovimiento), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocidadMovimiento_MetaData), NewProp_VelocidadMovimiento_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_RangoVision = { "RangoVision", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APrototypeEnemigo1, RangoVision), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RangoVision_MetaData), NewProp_RangoVision_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_JugadorDetectado = { "JugadorDetectado", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APrototypeEnemigo1, JugadorDetectado), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JugadorDetectado_MetaData), NewProp_JugadorDetectado_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrototypeEnemigo1_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_PuntoA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_PuntoB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_VelocidadMovimiento,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_RangoVision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrototypeEnemigo1_Statics::NewProp_JugadorDetectado,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeEnemigo1_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APrototypeEnemigo1_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeEnemigo1_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APrototypeEnemigo1_Statics::ClassParams = {
	&APrototypeEnemigo1::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APrototypeEnemigo1_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeEnemigo1_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeEnemigo1_Statics::Class_MetaDataParams), Z_Construct_UClass_APrototypeEnemigo1_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APrototypeEnemigo1()
{
	if (!Z_Registration_Info_UClass_APrototypeEnemigo1.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APrototypeEnemigo1.OuterSingleton, Z_Construct_UClass_APrototypeEnemigo1_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APrototypeEnemigo1.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<APrototypeEnemigo1>()
{
	return APrototypeEnemigo1::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APrototypeEnemigo1);
APrototypeEnemigo1::~APrototypeEnemigo1() {}
// End Class APrototypeEnemigo1

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_Prototypes_PrototypeEnemigo1_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APrototypeEnemigo1, APrototypeEnemigo1::StaticClass, TEXT("APrototypeEnemigo1"), &Z_Registration_Info_UClass_APrototypeEnemigo1, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APrototypeEnemigo1), 1408340190U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_Prototypes_PrototypeEnemigo1_h_134900306(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_Prototypes_PrototypeEnemigo1_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_HP_VICTUS_CORE_i5_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Public_Prototypes_PrototypeEnemigo1_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
