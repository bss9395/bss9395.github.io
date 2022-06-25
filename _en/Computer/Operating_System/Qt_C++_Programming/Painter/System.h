/* System.h
Author: BSS9395
Update: 2022-06-25T22:47:00+08@China-Shanghai+08
Design: Painter
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef System_h
#define System_h

#define Header_h
#include "Common.h"

typedef intptr_t iptr;
typedef size_t   uptr;
typedef wchar_t  wide;

typedef const char* Bool;
static inline const Bool _None = "None";
static inline const Bool _Posi = "Posi";
static inline const Bool _Nega = "Nega";

Q_DECLARE_METATYPE(iptr);
Q_DECLARE_METATYPE(uptr);
Q_DECLARE_METATYPE(wide);
Q_DECLARE_METATYPE(Bool);

class Registration {
public:
    static iptr Register() {
        iptr ret = 0;

        qRegisterMetaType<iptr>("iptr");
        qRegisterMetaType<uptr>("uptr");
        qRegisterMetaType<wide>("wide");
        qRegisterMetaType<Bool>("Bool");
        ret += 4;

        return ret;
    }
    static inline iptr _register = Register();
};

////////////////////////////////////////////////////////////////////////////////

// note: the difference of two addresses can exceed the range of iptr type, although it's impossible.
#define Index_Class(Object, _member)   (((uptr)&((Object *)0)->_member - (uptr)0) / (uptr)sizeof(((Object *)0)->_member))
#define Index_Object(object, _member)  (((uptr)&object._member - (uptr)&object)   / (uptr)sizeof(object._member))
#define Offset_Class(Object, _member)   ((uptr)&((Object *)0)->_member - (uptr)0)
#define Offset_Object(object, _member)  ((uptr)&object._member - (uptr)&object)

////////////////////////////////////////////////////////////////////////////////

struct System {
    static inline iptr _Success = iptr(0);
    static inline iptr _Failure = iptr(1);
    static inline iptr _Deprecated = iptr(2);

    typedef const char* Level;
    static inline const Level _Note = Level("Note");
    static inline const Level _Warn = Level("Warn");
    static inline const Level _Error = Level("Error");
    static inline const Level _Fatal = Level("Fatal");

    ////////////////////////////////////

    static iptr Log(iptr line, const char* format, ...) {
        fprintf(stderr, "[%td] ", line);

        va_list list;
        va_start(list, format);
        vfprintf(stderr, format, list);
        va_end(list);

        fprintf(stderr, "%ls", L";\n");
        fflush(stderr);
        return line;
    }
#define Logging(...) Log(__LINE__, __VA_ARGS__)

    static bool Check(bool failed, Level level, const char* file, iptr line, const char* function, const char* record, const char* extra, ...) {
        // Logging(__FUNCTION__);
        if (failed == true) {
            const char* sepa = NULL;
            (sepa = strrchr(file, '/')) || (sepa = strrchr(file, '\\'));
            fprintf(stderr, "[%s : %s : %td : %s] %s", (char*)level, (sepa == NULL) ? file : (sepa + 1), (iptr)line, function, record);

            if (extra != NULL) {
                fprintf(stderr, " : ");
                va_list list;
                va_start(list, extra);
                vfprintf(stderr, extra, list);
                va_end(list);
            }

            fprintf(stderr, ";\n");
            fflush(stderr);
        }
        return failed;
    }
#define Checking(failed, level, ...) Check(failed, level, __FILE__, __LINE__, __FUNCTION__, ""#failed, __VA_ARGS__)
};

////////////////////////////////////////////////////////////////////////////////

struct Format {
    static const char* Signify(const char* sign) {
        return sign;
    }
#define Signifying(sign)    Signify(""#sign)

    template<typename TType>
    static TType Functor(TType type) {
        return type;
    }

    template<typename TBuffer = QString>
    static TBuffer& Buffer(const iptr capacity = 1024, const iptr shrink = 2048) {
        // Logging(__FUNCTION__);
        static TBuffer buffer = TBuffer(capacity, 0);
        if ((iptr)buffer.capacity() > shrink) {
            buffer.shrink_to_fit();
        }
        if ((iptr)buffer.capacity() < capacity) {
            buffer.reserve(capacity);
        }
        return buffer;
    }

#define None
#define Print_Member(Member, TBuffer)                                                                                                    \
    [](const auto &container, TBuffer &buffer = Format::Buffer<QString>(1024, 2048), const TBuffer &sepa = QString(", ")) -> TBuffer & { \
        buffer.clear();                                                                                                                  \
        if (0 < container.size()) {                                                                                                      \
            auto beg = container.begin(), end = container.end();                                                                         \
            for (buffer += (*beg)Member, beg++; beg != end; buffer += sepa, buffer += (*beg)Member, beg++);                              \
        }                                                                                                                                \
        return buffer;                                                                                                                   \
    }                                                                                                                                    \
// Leave Blank Space
#define Lambda_Print(Member, TBuffer) Functor(Print_Member(Member, TBuffer))    // note: here Function wrapper is necessary.
    static inline const auto Print = Functor(Print_Member(None, QString));  // note: here Function wrapper is unnecessary.
};

////////////////////////////////////////////////////////////////////////////////

template<typename TType>
class Property {
public:
    typedef std::function<void(void)> Functor;

    TType _value;
    Functor _function;
    bool _once = false;

public:
    Property(const TType& value = TType(), const Functor& function = Functor()) {
        // System::Logging(__FUNCTION__);
        _value = value;
        _function = function;
    }

    TType& operator=(const TType& value) {
        // System::Logging(__FUNCTION__);
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _function();
        }
        _once = false;
        return _value;
    }

    operator TType& () {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

template<>
class Property<Bool> {
public:
    typedef std::function<void(void)> Functor;

public:
    Bool _value = _None;
    Functor _function = Functor();
    bool _once = false;

public:
    Property(const Bool& value = _None, const Functor& function = Functor()) {
        // System::Logging("Property(const Bool &value = _None, const Function &function = Function()) {");
        _value = value;
        _function = function;
    }

    Property(const bool& value = bool(), const Functor& function = Functor()) {
        // System::Logging("Property(const bool &value = bool(), const Function &function = Function()) {");
        _value = (value == true) ? _Posi : _Nega;
        _function = function;
    }

    Bool& operator=(const Bool& value) {
        // System::Logging("Bool &operator=(const Bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _function();
        }
        _once = false;
        return _value;
    }

    Bool& operator=(const bool& value) {
        // System::Logging("Bool &operator=(const bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = (value == true) ? _Posi : _Nega;
            _function();
        }
        _once = false;
        return _value;
    }

    operator Bool& () {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

////////////////////////////////////////////////////////////////////////////////

template<const iptr = 0, typename ...>
struct Proto;

template<typename TType, typename ...TTypes>
struct Proto<0, TType, TTypes...> {
    typedef TType Type;
    static inline const iptr _Offset = 0;
};

template<const iptr Idx, typename TType, typename ...TTypes>
struct Proto<Idx, TType, TTypes...> {
    typedef typename Proto<Idx - 1, TTypes...>::Type Type;
    static inline const iptr _Offset = sizeof(TType) + Proto<Idx - 1, TTypes...>::_Offset;
};

template<typename ...>
struct Sequence;

template<>
struct Sequence<> {
public:
    static inline const iptr _Argc = 0;
    static inline const iptr _Size = 0;

public:
    Sequence() {
        // System::Logging(__FUNCTION__);
    }

    virtual ~Sequence() {
        // System::Logging(__FUNCTION__);
    }

public:
    template<typename TType>
    Sequence& operator=(const TType& type) {  // note: do nothing.
        System::Logging(__FUNCTION__);

        (void) type;
        return (*this);
    }

public:
    template<typename TType, typename ...TTypes>
    static auto Make(const TType& type, const TTypes &...types) {
        System::Logging(__FUNCTION__);

        return Sequence<TType, TTypes...>(type, types...);
    }
};
static Sequence<> _Ignore = Sequence<>();


template<typename TType, typename ...TTypes>
struct Sequence<TType, TTypes...> {
public:
    static inline const iptr _Argc = 1 + sizeof...(TTypes);
    static inline const iptr _Size = sizeof(TType) + Sequence<TTypes...>::_Size;

public:
    iptr* _refer = nullptr;
    char* _objects = nullptr;

public:
    explicit Sequence() {
        // System::Logging(__FUNCTION__);

        _refer = new iptr(0);
        (*_refer) += 1;
    }

    // note: [const TType &] will transform the actual type, [TType &&] will not parse the actual type.
    explicit Sequence(const TType& type, const TTypes &...types) {
        // System::Logging(__FUNCTION__);

        // std::cout << "_Argc = " << _Argc << ", _Size = " << _Size << std::endl;
        // std::cout << "typeid(TType).name() = " << typeid(TType).name() << std::endl;
        // std::cout << "typeid(TType &).name() = " << typeid(TType &).name() << std::endl;

        _refer = new iptr(0);
        _objects = (char*)::operator new(_Size);  // note: allocate memory.
        char* address = _objects;
        char* inplace[] = {
            // note: unwind the variadic parameter types.
            (Construct(address, type), address += sizeof(TType)),
            (Construct(address, types), address += sizeof(TTypes))...
        };
        (void) inplace;
        (*_refer) += 1;
    }

    Sequence(const Sequence& sequence) {
        // System::Logging(__FUNCTION__);

        _refer = sequence._refer;
        _objects = sequence._objects;
        (*_refer) += 1;
    }

    Sequence& operator=(const Sequence& sequence) {
        // System::Logging(__FUNCTION__);

        if (this != &sequence) {
            this->~Sequence();
            _refer = sequence._refer;
            _objects = sequence._objects;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Sequence() {
        // System::Logging(__FUNCTION__);

        (*_refer) -= 1;
        if ((*_refer) <= 0 && _objects != nullptr) {
            Reverse<TType, TTypes...>(_objects);
            ::operator delete(_objects);           // note: deallocate memory.
        }
    }

public:
    template<typename TAddress>
    void Construct(char* address, const TAddress& object) {
        // System::Logging(__FUNCTION__);

        new (address) TAddress(object);
    }

    template<typename TAddress, const iptr numb>
    void Construct(char* address, const TAddress(&objects)[numb]) {
        // System::Logging(__FUNCTION__);

        for (iptr i = 0; i < numb; i += 1) {
            Construct(address, objects[i]), address += sizeof(TAddress);
        }
    }

    template<const iptr = 0, const iptr = 0>
    void Reverse(char* address) {  // note: do nothing.
        // System::Logging(__FUNCTION__);

        (void)address;
        return;
    }

    template<typename TAddress, typename ...TAddresses>
    void Reverse(char* address) {
        // System::Logging(__FUNCTION__);

        // std::cout << "typeid(TAddress).name()" << typeid(TAddress).name() << std::endl;
        // std::cout << "typeid(TAddress *).name()" << typeid(TAddress *).name() << std::endl;

        Reverse<TAddresses...>(address + sizeof(TAddress));
        Destruct((TAddress*)address);
    }

    template<typename TObject>
    void Destruct(TObject* object) {
        // System::Logging(__FUNCTION__);

        object->~TObject();
    }

    template<typename TObject, const iptr numb>
    void Destruct(TObject(*objects)[numb]) {
        // System::Logging(__FUNCTION__);

        // std::cout << "typeid(TObject).name() = " << typeid(TObject).name() << std::endl;
        // std::cout << "typeid(objects).name() = " << typeid(objects).name() << std::endl;

        for (iptr i = numb - 1; 0 <= i; i -= 1) {
            Destruct((TObject*)&(*objects)[i]);
        }
    }

public:
    template<const iptr Idx>
    auto& At() const {  // note: [auto <= auto &], reference type will automatically transform to pointer type.
        System::Logging(__FUNCTION__);

        typedef typename Proto<Idx, TType, TTypes...>::Type Type;
        const iptr offset = Proto<Idx, TType, TTypes...>::_Offset;
        // std::cout << "typeid(Type).name() = " << typeid(Type).name() << std::endl;

        return *(Type*)(_objects + offset);
    }

public:
    template<typename TRefer, typename ...TRefers>
    void Unwind(TRefer& refer, TRefers &...refers) {
        System::Logging(__FUNCTION__);

        char* address = _objects;
        char* inplace[] = {
            // note: unwind the variadic parameter refers.
            (Assign(&refer, (TType*)address), address += sizeof(TType)),
            (Assign(&refers, (TTypes*)address), address += sizeof(TTypes))...
        };
    }

    template<typename TRefer, typename TObject>
    static void Assign(TRefer* refer, TObject* object) {
        System::Logging(__FUNCTION__);

        // std::cout << "typeid(refer).name() = " << typeid(refer).name() << std::endl;
        // std::cout << "typeid(object).name() = " << typeid(object).name() << std::endl;
        (*refer) = (*object);   // note: if left type is compatible with right type.
    }

    template<typename TRefer, const iptr numb, typename TObject, const iptr size>
    static void Assign(TRefer(*refers)[numb], TObject(*objects)[size]) {
        System::Logging(__FUNCTION__);

        if (numb > size) {
            throw QString("if (numb > size) {");
        }
        for (iptr i = 0; i < numb; i += 1) {
            Assign((TRefer*)&(*refers)[i], (TObject*)&(*objects)[i]);
        }
    }

public:
    template<typename TRefer, typename ...TRefers>
    void Unpack(TRefer& refer, TRefers &...refers) {
        System::Logging(__FUNCTION__);

        Shift(_objects, &refer, &refers...);
    }

    template<const iptr = 0, const iptr = 0>
    static void Shift(char* address) {  // note: do nothing.
        System::Logging(__FUNCTION__);

        (void) address;
        return;
    }

    template<typename TRefer, typename ...TRefers>
    static void Shift(char* address, TRefer* refer, TRefers *...refers) {
        System::Logging(__FUNCTION__);

        Assign(refer, (TType*)address);
        Sequence<TTypes...>::Shift(address + sizeof(TType), refers...);
    }
};

////////////////////////////////////////////////////////////////////////////////

class Clean {
public:
    typedef std::function<void(void)> Functor;
    typedef const char* Done;
    static inline const Done _Hitted = "Hitted";
    static inline const Done _Missed = "Missed";

public:
    struct Class {
        virtual ~Class() {
            System::Logging(__FUNCTION__);
        }
    };
    static inline std::set<std::vector<Class*>*> _Set;

public:
    iptr* _refer = nullptr;
    Functor* _function = nullptr;
    std::vector<Class*>* _pointers = nullptr;

public:
    Clean() {
        System::Logging(__FUNCTION__);

        _refer = new iptr(0);
        (*_refer) += 1;
    }

    Clean(const Functor& function) {
        System::Logging(__FUNCTION__);

        _refer = new iptr(0);
        _function = new Functor(function);
        (*_refer) += 1;
    }

    Clean(const Clean& clean) {
        System::Logging(__FUNCTION__);

        _refer = clean._refer;
        _function = clean._function;
        _pointers = clean._pointers;
        (*_refer) += 1;
    }

    Clean& operator=(const Clean& clean) {
        System::Logging(__FUNCTION__);

        if (this != &clean) {
            this->~Clean();
            _refer = clean._refer;
            _function = clean._function;
            _pointers = clean._pointers;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Clean() {
        System::Logging(__FUNCTION__);

        if (_function != nullptr) {
            (*_function)();
        }

        ////////////////////////////////

        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            if (_function != nullptr) {
                delete _function;
            }
            if (_pointers != nullptr) {
                if (0 < (*_pointers).size()) {
                    for (iptr i = 0, size = (*_pointers).size(); i < size; i += 1) {
                        delete (*_pointers)[i];
                    }
                }
                Clean::_Set.erase(_pointers);
                delete _pointers;
            }
        }
    }

public:
    Clean& Auto_Pointer(void* pointer) {
        System::Logging(__FUNCTION__);

        if (_pointers == nullptr) {
            _pointers = new std::vector<Class*>();
            Clean::_Set.insert(_pointers);
        }
        _pointers->push_back((Class*)pointer);
        return (*this);
    }

    Done Clean_Pointer(void* pointer) {
        System::Logging(__FUNCTION__);

        if (_pointers != nullptr && 0 < (*_pointers).size()) {
            for (iptr i = 0, size = (*_pointers).size(); i < size; i += 1) {
                if ((*_pointers)[i] == pointer) {
                    delete (*_pointers)[i];
                    (*_pointers)[i] = nullptr;
                    return _Hitted;
                }
            }
        }
        return _Missed;
    }
};

////////////////////////////////////////////////////////////////////////////////

template<typename TRecord, typename TSolution> class Anomaly;
class Exception : public std::exception {
public:
    virtual QString& Report() {
        static QString report = QString(__FUNCTION__);
        return report;
    }

    [[deprecated("obsolete function what(), use Report() instead.")]]
    virtual const char* what() const noexcept override final {
        System::Check(true, System::_Note, __FILE__, __LINE__, __FUNCTION__, "obsolete function what()", " use Report() instead.");
        exit((int)System::_Deprecated);
    }

public:
    template<typename TRecord = QString, typename TSolution = QString>
    static bool Except(bool failed, System::Level level, const QString& file, iptr line, const QString& function, const TRecord& record, const TSolution& solution = TSolution()) {
        if (failed == true) {
            throw Anomaly(level, file, line, function, record, solution);
        }
        return failed;
    }
#define Excepting(failed, level, record, solution)    Except(failed, level, __FILE__, __LINE__, __FUNCTION__, record, solution)
};

template<typename TRecord = QString, typename TSolution = QString>
class Anomaly : public Exception {
public:
    iptr* _refer = nullptr;
    struct Datum {
        System::Level _level = System::Level();
        QString _file = "";
        iptr _line = 0;
        QString _function = "";
        TRecord _record;        // note: in C++, array can not be assigned.
        TSolution _solution;    // note: in C++, array can not be assigned.
        QString _report = "";
    } *_datum = nullptr;

public:
    Anomaly(System::Level level, const QString& file, iptr line, const QString& function, const TRecord& record, const TSolution& solution) {
        System::Logging(__FUNCTION__);
        _refer = new iptr(0);
        _datum = new Datum();
        _datum->_level = level;
        _datum->_file = file;
        _datum->_line = line;
        _datum->_function = function;
        _datum->_record = record;
        _datum->_solution = solution;
        (*_refer) += 1;
    }

    Anomaly(System::Level level, const QString& file, iptr line, const QString& function, const char* record, const char* solution) {
        System::Logging(__FUNCTION__);

        _refer = new iptr(0);
        _datum = new Datum();
        _datum->_level = level;
        _datum->_file = file;
        _datum->_line = line;
        _datum->_function = function;
        _datum->_record = record;
        _datum->_solution = solution;
        (*_refer) += 1;
    }

    Anomaly(const Anomaly& anomaly) {
        System::Logging(__FUNCTION__);

        _refer = anomaly._refer;
        _datum = anomaly._datum;
        (*_refer) += 1;
    }

    Anomaly& operator=(const Anomaly& anomaly) {
        System::Logging(__FUNCTION__);

        if (this != &anomaly) {
            this->~Anomaly();
            _refer = anomaly._refer;
            _datum = anomaly._datum;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Anomaly() {
        System::Logging(__FUNCTION__);
        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            delete _refer;
            delete _datum;
        }
    }

public:
    virtual QString& Report() override {
        // System::Logging(__FUNCTION__);
        _datum->_report = "";

        iptr sepa = -1;
        ((sepa = _datum->_file.lastIndexOf('/')) < 0) && (sepa = _datum->_file.lastIndexOf('\\'));
        _datum->_report += QString("[%1 : %2 : %3 : %4] ").arg(_datum->_level).arg(_datum->_file.mid(sepa + 1)).arg(_datum->_line).arg(_datum->_function);
        _datum->_report += _datum->_record, _datum->_report += " : ";
        _datum->_report += _datum->_solution, _datum->_report += ";";
        return _datum->_report;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Thread : public QThread {
public:
    typedef const char *State;
    static inline State _Created = State("Created");
    static inline State _Running = State("Running");
    static inline State _Blocked = State("Blocked");
    static inline State _Stopped = State("Stopped");

public:
    State _state = _Created;

public:
    explicit Thread() {
        System::Logging(__FUNCTION__);
    }

    virtual ~Thread() override {
        System::Logging(__FUNCTION__);
    }

public:
    void Transfer(const State &state) {
        System::Logging(__FUNCTION__);

        _state = state;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Configuration {
public:
    static iptr Configure() {
        System::Logging(__FUNCTION__);

        iptr ret = 0;

        // ".936" for windows, "zh_CN.GBK" for linux.
        if ((char*)setlocale(LC_ALL, "") == NULL) {
            System::Logging("%s", "invalid locale");
            exit((int)System::_Failure);
        }
        ret += 1;

        System::Logging("timestamp = %s", __TIMESTAMP__);
        ret += 1;

        return ret;
    }
    static inline iptr _configure = Configure();
};

#endif // System_h
