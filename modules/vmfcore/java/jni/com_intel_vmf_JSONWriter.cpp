#include<string>
#include<vector>
#include "vmf/jsonwriter.hpp"
#include "../com_intel_vmf_JSONWriter.h"
#include "throwJavaException.hpp"

using namespace vmf;

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_JSONWriter
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_JSONWriter_n_1JSONWriter (JNIEnv *env, jclass)
{
    std::shared_ptr<JSONWriter>* p = new std::shared_ptr<JSONWriter>(new JSONWriter());
    return (jlong)p;
}


/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSchemas
 * Signature: (J[J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSchemas (JNIEnv *env, jclass, jlong self, jlongArray schemaAddrs)
{
    static const char method_name[] = "JSONWriter::n_1storeSchemas";

    try
    {
        std::shared_ptr<JSONWriter>* obj = (std::shared_ptr<JSONWriter>*) self;
        std::vector <std::shared_ptr<MetadataSchema>> vecSchemas;

        jlong* schemasArray = env->GetLongArrayElements(schemaAddrs, 0);
        jsize lenSchemas = env->GetArrayLength (schemaAddrs);

        for (int j = 0; j < lenSchemas; j++)
        {
            std::shared_ptr<MetadataSchema>* pSpSchema = (std::shared_ptr<MetadataSchema>*) schemasArray[j];
            vecSchemas.push_back (*pSpSchema);
        }

        env->ReleaseLongArrayElements (schemaAddrs, schemasArray, 0);

        std::string str = (*obj)->store (vecSchemas);
        return env->NewStringUTF(str.c_str());
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeMetadataSet
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeMetadataSet (JNIEnv *env, jclass, jlong self, jlong setAddr)
{
    static const char method_name[] = "JSONWriter::n_1storeMetadataSet";

    try
    {
        std::shared_ptr<JSONWriter>* obj = (std::shared_ptr<JSONWriter>*) self;
        std::shared_ptr<MetadataSet>* set = (std::shared_ptr<MetadataSet>*) setAddr;

        std::string str = (*obj)->store(**set);
        return env->NewStringUTF(str.c_str());
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeAll
 * Signature: (JJLjava/lang/String;Ljava/lang/String;[J[JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeAll (JNIEnv *env, jclass, jlong self, jlong nextId, jstring path, jstring checksum, jlongArray segAddrs, jlongArray schemaAddrs, jlong setAddr)
{
    static const char method_name[] = "JSONWriter::n_1storeAll";

    try
    {
        std::shared_ptr<JSONWriter>* obj = (std::shared_ptr<JSONWriter>*) self;
        std::shared_ptr<MetadataSet>* set = (std::shared_ptr<MetadataSet>*) setAddr;

        std::vector <std::shared_ptr<MetadataStream::VideoSegment>> vecSegments;
        std::vector <std::shared_ptr<MetadataSchema>> vecSchemas;

        const char* file = env->GetStringUTFChars(path, NULL);
        const char* sum = env->GetStringUTFChars(checksum, NULL);

        std::string sPath(file);
        std::string sChecksum(sum);

        jlong* segmentsArray = env->GetLongArrayElements (segAddrs, 0);
        jlong* schemasArray = env->GetLongArrayElements (schemaAddrs, 0);

        jsize lenSegments = env->GetArrayLength (segAddrs);
        jsize lenSchemas = env->GetArrayLength (schemaAddrs);

        for (int i = 0; i < lenSegments; i++)
        {
            std::shared_ptr<MetadataStream::VideoSegment>* pSpSegment = (std::shared_ptr<MetadataStream::VideoSegment>*) segmentsArray[i];
            vecSegments.push_back(*pSpSegment);
        }

        for (int j = 0; j < lenSchemas; j++)
        {
            std::shared_ptr<MetadataSchema>* pSpSchema = (std::shared_ptr<MetadataSchema>*) schemasArray[j];
            vecSchemas.push_back(*pSpSchema);
        }

        env->ReleaseLongArrayElements(segAddrs, segmentsArray, 0);
        env->ReleaseLongArrayElements(schemaAddrs, schemasArray, 0);

        env->ReleaseStringUTFChars(path, file);
        env->ReleaseStringUTFChars(checksum, sum);

        std::string str = (*obj)->store((IdType&)nextId, sPath, sChecksum, vecSegments, vecSchemas, (**set));
        return env->NewStringUTF(str.c_str());
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSegment
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSegment (JNIEnv *env, jclass, jlong self, jlong segAddr)
{
    static const char method_name[] = "JSONWriter::n_1storeSegment";

    try
    {
        std::shared_ptr<JSONWriter>* obj = (std::shared_ptr<JSONWriter>*) self;
        std::shared_ptr<MetadataStream::VideoSegment>* segment = (std::shared_ptr<MetadataStream::VideoSegment>*) segAddr;

        std::string str = (*obj)->store(*segment);
        return env->NewStringUTF (str.c_str());
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_storeSegments
 * Signature: (J[J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_intel_vmf_JSONWriter_n_1storeSegments (JNIEnv *env, jclass, jlong self, jlongArray segAddrs)
{
    static const char method_name[] = "JSONWriter::n_1storeSegments";

    try
    {
        std::shared_ptr<JSONWriter>* obj = (std::shared_ptr<JSONWriter>*) self;
        std::vector <std::shared_ptr<MetadataStream::VideoSegment>> vecSegments;

        jlong* segmentsArray = env->GetLongArrayElements(segAddrs, 0);
        jsize lenSegments = env->GetArrayLength(segAddrs);

        for (int i = 0; i < lenSegments; i++)
        {
            std::shared_ptr<MetadataStream::VideoSegment>* pSpSegment = (std::shared_ptr<MetadataStream::VideoSegment>*) segmentsArray[i];
            vecSegments.push_back(*pSpSegment);
        }

        env->ReleaseLongArrayElements (segAddrs, segmentsArray, 0);

        std::string str = (*obj)->store(vecSegments);
        return env->NewStringUTF(str.c_str());
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }

    return 0;
}

/*
 * Class:     com_intel_vmf_JSONWriter
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_intel_vmf_JSONWriter_n_1delete (JNIEnv *env, jclass, jlong self)
{
    static const char method_name[] = "JSONWriter::n_1delete";

    try
    {
        std::shared_ptr<JSONWriter>* p = (std::shared_ptr<JSONWriter>*) self;
        delete p;
    }
    catch (const std::exception &e)
    {
        throwJavaException(env, &e, method_name);
    }
    catch (...)
    {
        throwJavaException(env, 0, method_name);
    }
}
