#include <string>
#include <sstream>
#include "JNIWorkspace.h"
#include "../Workspace.h"

JNIEXPORT jlong JNICALL Java_JNIWorkspace_initWorkspace
  (JNIEnv *env, jobject obj)
{
  return (jlong) new Workspace();
}

JNIEXPORT void JNICALL Java_JNIWorkspace_deleteWorkspace
  (JNIEnv *env, jobject obj, jlong wsPtr)
{
  Workspace* ws = (Workspace *) wsPtr;
  delete ws;
}


JNIEXPORT void JNICALL Java_JNIWorkspace_newMatrix
  (JNIEnv *env, jobject obj, jlong wsPtr, jstring matrix)
{

  const char *str_matrix = env->GetStringUTFChars(matrix, 0);

  istringstream is(str_matrix);
  string name;
  Matrix ms;
  
  is >> name;
  is >> ms;

  Workspace *ws = (Workspace *) wsPtr;
  
  ws->newMatrix(name, ms);  
  
  env->ReleaseStringUTFChars(matrix, str_matrix);

}

JNIEXPORT jstring JNICALL Java_JNIWorkspace_findMatrix
  (JNIEnv *env, jobject obj, jlong wsPtr, jstring name)
{
  Workspace *ws = (Workspace *) wsPtr;

  const char* str_name = env->GetStringUTFChars(name, 0);

  Matrix* m = ws->findMatrix(str_name);

  env->ReleaseStringUTFChars(name, str_name);
  
  ostringstream os;
  os << (*m);

  string str_matrix = os.str();
  
  return env->NewString((jchar *)str_matrix.c_str(), (jsize)str_matrix.length());
  
}

JNIEXPORT void JNICALL Java_JNIWorkspace_deleteMatrix
  (JNIEnv *env, jobject obj, jlong wsPtr, jstring name)
{

}

JNIEXPORT void JNICALL Java_JNIWorkspace_updateMatrix
  (JNIEnv *env, jobject obj, jlong wsPtr, jstring matrix)
{

}

JNIEXPORT jstring JNICALL Java_JNIWorkspace_resolveExpression
  (JNIEnv *env, jobject obj, jlong wsPtr, jstring expression)
{

}
