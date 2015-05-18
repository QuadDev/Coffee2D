#pragma once
//META INFO
//Author: 양교원(gyowonhikari@gmail.com)

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <d3dx11.h>
#include <d3d11.h>
#include <D3dx9math.h>

//Define
namespace Coffee2D
{
#if defined(ENGINE_EXPORTS)
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

	/**
	* @brief	From 데이터형에서 To 데이터형으로 변환이 가능하면 enable 되도록 해줍니다.
	* @use		template<class _Ty2,
	*			typename Enable = ENABLE_IF_CONVERTIBLE(_Ty2, Type)>
	*			void add(_Ty2 _value) { ... } //만약 변환불가능시 add 는 인스턴스화되지않음.
	*/
#define ENABLE_IF_CONVERTIBLE(from, to) boost::enable_if_c<boost::is_convertible<from, to>::value>::type

	/**
	* @brief	From 데이터형에서 To 데이터형으로 변환이 가능하면 disable 되도록 해줍니다.
	* @use		template<class _Ty2,
	*			typename Disable = DISABLE_IF_CONVERTIBLE(_Ty2, Type)>
	*			void add(_Ty2 _value) { ... } //만약 변환가능시 add 는 인스턴스화되지않음.
	*/
#define DISABLE_IF_CONVERTIBLE(from, to) boost::enable_if_c<!boost::is_convertible<from, to>::value>::type

	/**
	* @brief	DATATYPE 이 Pointer 일때 Disable 시켜줍니다.
	* @use		template<class Type,
	*			typename Disable = DISABLE_IF_PTR(Type)>
	*/
#define DISABLE_IF_PTR(DATATYPE) boost::enable_if_c<!boost::is_pointer<DATATYPE>::value>::type

	/**
	* @brief	DATATYPE 이 POD(Plain Of Data) 일때 Enable 되도록 해줍니다.
	* @use		template<class Type, typename Enable = ENABLE_IF_POD(Type)>
	*			void add(Type _value) { ... } //만약 POD 가 아니면 add 가 인스턴스화 되지않음.
	*/
#define ENABLE_IF_POD(DATATYPE) boost::enable_if_c<boost::is_pod<DATATYPE>::value>::type

#define GETSETTER(DATATYPE, VALNAME, FUNCNAME) \
	inline void set##FUNCNAME(DATATYPE val) { this->VALNAME = val;} \
	inline DATATYPE get##FUNCNAME() { return this->VALNAME;}

}

//Data Types
namespace Coffee2D
{
	using uint8 = unsigned char;				//		8비트 부호없는 정수 데이터형 ( 8 bit Unsigned Integer data type), unsigned char)		
	using uint16 = unsigned short int;			//		16비트 부호없는 정수 데이터형 ( 16 bit Unsigned Integer data type), unsigned short int)	
	using uint32 = unsigned int;				//		32비트 부호없는 정수 데이터형 ( 32 bit Unsigned Integer data type), unsigned int)			
	using uint64 = unsigned long long;			//		64비트 부호없는 정수 데이터형 ( 64 bit unsigned Integer data type), unsigned long long)

	using int8 = signed char;					//		8비트 부호있는 정수 데이터형 ( 8 bit Signed Integer data type), signed char)
	using int16 = signed short int;				//		16비트 부호있는 정수 데이터형 ( 16 bit Signed Integer data type), signed short int)
	using int32 = signed int;					//		32비트 부호있는 정수 데이터형 ( 32 bit Signed Integer data type), signed int)
	using int64 = signed long long;				//		64비트 부호있는 정수 데이터형 ( 64 bit Signed Integer data type), signed long long)

	using ANSICHAR = char;						//		ANSI 표준 문자 데이터형 ( ANSI Standard Character data type), char)
	using WIDECHAR = wchar_t;					//		Wide 문자 데이터형 ( Wided Character data type), wchar_t)

	using TYPE_OF_NULL = int32;					//		NULL 의 데이터형 ( NULL data type), int32)
	using TYPE_OF_NULLPTR = decltype(nullptr);	//		nullptr 의 데이터형 ( nullptr data type), decltype(nullptr)
}