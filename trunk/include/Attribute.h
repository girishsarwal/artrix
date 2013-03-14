#pragma once
class Attribute{
private:
	std::string name;
	std::string value;
public:
	Attribute(){
	};
	void set(const char* _name, const char* _value){
		name = std::string(_name);
		value = std::string(_value);
	}
	
	const char* getName(){
		return name.c_str();
	};
	const char* getValue(){
		return value.c_str();
	};
};
class AttributeSet{

private:
	std::map<std::string, Attribute> m_Attributes;
public:
		void add(Attribute& a){
			m_Attributes[a.getName()] = a;
		}
		Attribute& get(std::string key){
			return m_Attributes[key];
		}
};
