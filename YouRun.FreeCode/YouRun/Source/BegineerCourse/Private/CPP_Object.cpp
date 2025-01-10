// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Object.h"


int UCPP_Object::GetOurPrivateInterger()
{
	return OurPrivateIntergerVariable;
}

void UCPP_Object::SetOurPrivateInterger(UPARAM(ref)int& NewValue)
{
	OurPrivateIntergerVariable = NewValue;
	 
}

void UCPP_Object::Test(UPARAM(ref)FBook& Target, UObject* Context)
{
	UKismetSystemLibrary::PrintString(Context, "TestFunctionCalled");
}
