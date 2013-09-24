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
	void display(){
		printf("%s = %s,", name.c_str(), value.c_str());
	}
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
		void display(){
			printf("(");
			std::map<std::string, Attribute>::iterator it = m_Attributes.begin();
			while(it != m_Attributes.end()){
				printf("%s = %s, ", (it)->second.getName().c_str(), (it)->second.getValue().c_str());
				it++;
			}
			printf(")\n");
		}
};
