/*
 * Component.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_COMPONENT_H_
#define INCLUDE_COMPONENT_H_
#include "KeyManageable.h"
namespace gtfx {

class Component:
		public KeyManageable {
private:
	bool mIsEnabled;
    bool mIsInitialized;

public:
	Component();
	virtual ~Component();

	 bool GetIsInitialized() const;

	/** Lifecycle **/
	virtual bool ValidateAttributes();

	void BeforeInitialize();
	void Initialize();
	void AfterInitialize();

	void BeforeUpdate(double frameTime);
	void Update(double);
	void AfterUpdate(double frameTime);

	void BeforeDestroy();
	void Destroy();
	void AfterDestroy();

/** lifecycle hooks **/
	virtual void OnBeforeInitialize();          /** use to setup resources required for initialization **/
	virtual void OnInitialize();            /** use for initialization **/
	virtual void OnAfterInitialize();           /** use for validating intialization was successfully carried out **/
	virtual void OnBeforeUpdate(double frameTime);
	virtual void OnUpdate(double) = 0;
	virtual void OnAfterUpdate(double frameTime);
	virtual void OnBeforeDestroy();
	virtual void OnDestroy();
	virtual void OnAfterDestroy();

	bool GetIsEnabled() const;
	void SetIsEnabled(bool isEnabled);
};

} /* namespace gtfx */

#endif /* INCLUDE_COMPONENT_H_ */
