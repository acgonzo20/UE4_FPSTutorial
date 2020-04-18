// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSPROJECT_FPSProjectile_generated_h
#error "FPSProjectile.generated.h already included, missing '#pragma once' in FPSProjectile.h"
#endif
#define FPSPROJECT_FPSProjectile_generated_h

#define FPSProject_Source_FPSProject_FPSProjectile_h_13_SPARSE_DATA
#define FPSProject_Source_FPSProject_FPSProjectile_h_13_RPC_WRAPPERS
#define FPSProject_Source_FPSProject_FPSProjectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FPSProject_Source_FPSProject_FPSProjectile_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile)


#define FPSProject_Source_FPSProject_FPSProjectile_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile)


#define FPSProject_Source_FPSProject_FPSProjectile_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public:


#define FPSProject_Source_FPSProject_FPSProjectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSProjectile)


#define FPSProject_Source_FPSProject_FPSProjectile_h_13_PRIVATE_PROPERTY_OFFSET
#define FPSProject_Source_FPSProject_FPSProjectile_h_10_PROLOG
#define FPSProject_Source_FPSProject_FPSProjectile_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_SPARSE_DATA \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_RPC_WRAPPERS \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_INCLASS \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSProject_Source_FPSProject_FPSProjectile_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_SPARSE_DATA \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_INCLASS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_FPSProjectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSPROJECT_API UClass* StaticClass<class AFPSProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSProject_Source_FPSProject_FPSProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
