#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <algorithm>


namespace seneca
{
	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template <typename T>
	class Database
	{
		int m_ent{ 0 };
		std::string m_key[20];
		T m_value[20];
		std::string m_filename;
		static std::shared_ptr<Database<T>> m_instance;

		Database(const std::string& filename);
		void encryptDecrypt(T& value);

	pulbic:
		std::shared_ptr<Database<T>> getInstance(const std::string& dbFileName);
		Err_Status GetValue(const std::string& key, T& value);
		Err_Status SetValue(const std::string& key, const T& value);
		~Database();
	};

	template <typename T>
	static std::shared_ptr<Database<T>> Database<T>::m_instance = nullptr;

	template <typename T>
	Database<T>::Database(const std::string& filename)
	{
		std::ifstream file(filename);

		std::string line;
		m_filename = filename;

		while (std::getline(file, line))
		{
			std::stringstream ss(line);

			T value;
			std::string key;

			ss >> key >> value;
			std::replace(key.begin(), key.end(), "_", " ");
			
			encryptDecrypt(value);
			m_key[m_ent] = key;
			m_value[m_ent] = value;
			m_ent++;
		}
	}

	template <typename T>
	void Database<T>::encryptDecrypt(T& value) 
	{ 

	}

	template <>
	void Database<std::string>::encryptDecrypt(std::string& value)
	{
		const char secret[]{ "secret encryption key" };

		for (char& C : value)
		{
			for (const char& K : secret)
			{
				C = C ^ K;
			}
		}
	}

	template <>
	void Database<long long>::encryptDecrypt(long long& value)
	{
		const char secret[]{ "super secret encryption key" };

		foreach byte B in the parameter
			foreach character K in the secret
			B = B ^ K
	}


}

#endif

