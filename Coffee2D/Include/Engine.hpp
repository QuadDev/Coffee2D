#pragma once
//META INFO
//Author: �米��(gyowonhikari@gmail.com)

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
	* @brief	From ������������ To ������������ ��ȯ�� �����ϸ� enable �ǵ��� ���ݴϴ�.
	* @use		template<class _Ty2,
	*			typename Enable = ENABLE_IF_CONVERTIBLE(_Ty2, Type)>
	*			void add(_Ty2 _value) { ... } //���� ��ȯ�Ұ��ɽ� add �� �ν��Ͻ�ȭ��������.
	*/
#define ENABLE_IF_CONVERTIBLE(from, to) boost::enable_if_c<boost::is_convertible<from, to>::value>::type

	/**
	* @brief	From ������������ To ������������ ��ȯ�� �����ϸ� disable �ǵ��� ���ݴϴ�.
	* @use		template<class _Ty2,
	*			typename Disable = DISABLE_IF_CONVERTIBLE(_Ty2, Type)>
	*			void add(_Ty2 _value) { ... } //���� ��ȯ���ɽ� add �� �ν��Ͻ�ȭ��������.
	*/
#define DISABLE_IF_CONVERTIBLE(from, to) boost::enable_if_c<!boost::is_convertible<from, to>::value>::type

	/**
	* @brief	DATATYPE �� Pointer �϶� Disable �����ݴϴ�.
	* @use		template<class Type,
	*			typename Disable = DISABLE_IF_PTR(Type)>
	*/
#define DISABLE_IF_PTR(DATATYPE) boost::enable_if_c<!boost::is_pointer<DATATYPE>::value>::type

	/**
	* @brief	DATATYPE �� POD(Plain Of Data) �϶� Enable �ǵ��� ���ݴϴ�.
	* @use		template<class Type, typename Enable = ENABLE_IF_POD(Type)>
	*			void add(Type _value) { ... } //���� POD �� �ƴϸ� add �� �ν��Ͻ�ȭ ��������.
	*/
#define ENABLE_IF_POD(DATATYPE) boost::enable_if_c<boost::is_pod<DATATYPE>::value>::type

#define GETSETTER(DATATYPE, VALNAME, FUNCNAME) \
	inline void set##FUNCNAME(DATATYPE val) { this->VALNAME = val;} \
	inline DATATYPE get##FUNCNAME() { return this->VALNAME;}

}

//Data Types
namespace Coffee2D
{
	using uint8 = unsigned char;				//		8��Ʈ ��ȣ���� ���� �������� ( 8 bit Unsigned Integer data type), unsigned char)		
	using uint16 = unsigned short int;			//		16��Ʈ ��ȣ���� ���� �������� ( 16 bit Unsigned Integer data type), unsigned short int)	
	using uint32 = unsigned int;				//		32��Ʈ ��ȣ���� ���� �������� ( 32 bit Unsigned Integer data type), unsigned int)			
	using uint64 = unsigned long long;			//		64��Ʈ ��ȣ���� ���� �������� ( 64 bit unsigned Integer data type), unsigned long long)

	using int8 = signed char;					//		8��Ʈ ��ȣ�ִ� ���� �������� ( 8 bit Signed Integer data type), signed char)
	using int16 = signed short int;				//		16��Ʈ ��ȣ�ִ� ���� �������� ( 16 bit Signed Integer data type), signed short int)
	using int32 = signed int;					//		32��Ʈ ��ȣ�ִ� ���� �������� ( 32 bit Signed Integer data type), signed int)
	using int64 = signed long long;				//		64��Ʈ ��ȣ�ִ� ���� �������� ( 64 bit Signed Integer data type), signed long long)

	using ANSICHAR = char;						//		ANSI ǥ�� ���� �������� ( ANSI Standard Character data type), char)
	using WIDECHAR = wchar_t;					//		Wide ���� �������� ( Wided Character data type), wchar_t)

	using TYPE_OF_NULL = int32;					//		NULL �� �������� ( NULL data type), int32)
	using TYPE_OF_NULLPTR = decltype(nullptr);	//		nullptr �� �������� ( nullptr data type), decltype(nullptr)
}