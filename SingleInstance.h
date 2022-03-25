#pragma once
template <typename T>
class CSingleInstance
{
protected:
	CSingleInstance() {};
public:
	virtual ~CSingleInstance() {};

	static T * GetInstance()
	{
		static T * _instance = new T();
		return _instance;
	}
};

