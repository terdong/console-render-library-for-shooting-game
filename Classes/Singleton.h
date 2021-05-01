#ifndef TG__SINGLETON__H
#define TG__SINGLETON__H

template <typename T>
class CSingleton
{
public:
	static T* GetInstance() 
	{
		if(!_pInstance)
		{
			_bInitialized = true;
			_pInstance = new T;
		}
		assert(_pInstance != nullptr);
		return _pInstance;
	}

	static T& GetInstanceRef() 
	{
		if(!_pInstance)
		{
			_bInitialized = true;
			_pInstance = new T;
		}
		assert(_pInstance != nullptr);
		return (*_pInstance);
	}

	static void Release() 
	{
		if (_pInstance) 
		{
			delete _pInstance;
			_pInstance = nullptr;
		}
	}


	static bool _bInitialized;
protected:
	CSingleton()
	{
		assert(!_pInstance);
		assert(_bInitialized);
	}
private:
	static T* _pInstance;
	CSingleton(CSingleton const&);		// 복사 숨김
	CSingleton& operator=(CSingleton const&);	// 할당 숨김
};

template <typename T>
T* CSingleton<T>::_pInstance = nullptr;

template <typename T>
bool CSingleton<T>::_bInitialized = false;

#endif // TG__SINGLETON__H