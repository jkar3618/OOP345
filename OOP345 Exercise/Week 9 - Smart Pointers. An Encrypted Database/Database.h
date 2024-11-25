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
		static std::shared_ptr<Database<T>> getInstance(const std::string& dbFileName);
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

	template<typename T>
	inline Err_Status Database<T>::GetValue(const std::string& key, T& value)
	{
		Err_Status result = Err_Status::Err_NotFound;

		for (size_t i = 0; i < m_ent; i++)
		{
			if (m_key[i] == key)
			{
				value = m_value[i];
				result = Err_Status::Err_Success;
			}
		}

		return result;
	}

	template<typename T>
	inline Err_Status Database<T>::SetValue(const std::string& key, const T& value)
	{
		Err_Status result;

		std::string newKey = key;

		if (m_ent < 20)
		{

		std::replace(newKey.begin(), newKey.end(), '_', ' ');
		m_key[m_ent] = newKey;
		m_value[m_ent] = value;
		m_ent++;
		result = Err_Status::Err_Success;

		}
		else
		{
			result = Err_Status::Err_OutOfMemory;
		}

		return result;
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
		char* byte = (reinterpret_cast<char*>(&value));
		size_t nByte = sizeof(long long);


		for (const char& B : secret)
		{
			for (const char& K : secret)
			{
				B = B ^ K;
			}
		}

	}
	
	template<typename T>
	static std::shared_ptr<Database<T>> getInstance(const std::string& dbFileName) 
	{
		if (m_instance == nullptr)
		{
			m_instance = std::shared_ptr<Database<T>>(new Database<T>(dbFileName));
		}

		return m_instance;
	}
	template <typename T>
	Database<T>::~Database()
	{
		std::string backUp = m_filename + ".bkp.txt";
		std::ofstream file(backUp, std::ios::binary);

		for (size_t i = 0; i < m_ent; i++)
		{
			T value = m_value[i];
			encryptDecrypt(value);

			file << std::setw(25) << std::left << m_key[i] << "-> " << value << std::endl;
		}
	}



}

#endif

