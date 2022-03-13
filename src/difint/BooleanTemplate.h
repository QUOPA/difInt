#pragma once

namespace di {

	template <typename TF>
	struct _BOOLBASE 
	{
		typedef TF Type;
	};

	struct _TRUE : public _BOOLBASE<_TRUE> { static constexpr bool tfVal = true; };
	struct _FALSE : public _BOOLBASE<_FALSE> { static constexpr bool tfVal = false; };

	template <unsigned long long keyVal, unsigned long long keyValOther>
	struct VarChecker
	{
		typedef std::conditional<keyVal == keyValOther, _TRUE, _FALSE> Type;
	};

	//template <unsigned long long keyVal, typename InType>
	//struct VarCheck
	//{
	//	typedef std::conditional<keyVal == keyValOther, _TRUE, _FALSE> Type;
	//};


	template<typename LBOOL, typename RBOOL>
	struct BoolOR
	{
		typedef std::conditional<LBOOL::tfVal || RBOOL::tfVal, _TRUE, _FALSE> Type;
	};

	template <unsigned long long keyVal, unsigned long long keyValOther>
	auto VarCheckerFunc()
	{
		typedef std::conditional<keyVal == keyValOther, _TRUE, _FALSE> Type;
	};

	template<typename LBOOL, typename RBOOL>
	auto BoolORFunc(LBOOL inL, RBOOL inR)
	{
		return typename std::conditional<LBOOL::tfVal || RBOOL::tfVal, _TRUE, _FALSE>::type();
	};


}


