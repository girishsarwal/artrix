#pragma once
class Attribute{
private:
	std::string name;
	std::string value;
public:
	Attribute(){
	};
	void set(std::string _name, std::string _value){
		name = std::string(_name);
		value = std::string(_value);
	}
	
	std::string getName(){
		return name;
	};
	std::string getValue(){
		return value;
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
