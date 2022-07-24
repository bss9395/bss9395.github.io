/* System.h
Author: BSS9395
Update: 2022-07-25T00:06:00+08@China-Shanghai+08
Design: SharedLib_Pen
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
struct Boolean{
    const Bool _None = (Bool)"None";
    const Bool _Posi = (Bool)"Posi";
    const Bool _Nega = (Bool)"Nega";
};

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
//#define Lambda_Print(Member, TBuffer) Functor(Print_Member(Member, TBuffer))    // note: here Function wrapper is necessary.
//    static inline const auto Print = Functor(Print_Member(None, QString));  // note: here Function wrapper is unnecessary.
};

////////////////////////////////////////////////////////////////////////////////

template<typename TType>
class Property {
public:
    typedef std::function<void(void)> Functor;
    static inline const Functor _functor = []() -> void {};

    TType _value;
    Functor _setter;
    Functor _getter;
    bool _once = false;

public:
    explicit Property(const TType& value = TType(), const Functor& setter = _functor, const Functor& getter = _functor) {
        System::Logging("explicit Property(const TType& value = TType(), const Functor& setter = _functor, const Functor& getter = _functor) {");
        _value = value;
        _setter = setter;
        _getter = getter;
    }

    TType& operator=(const TType& value) {
        // System::Logging(__FUNCTION__);
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _setter();
        }
        _once = false;
        return _value;
    }

    operator TType () {
        // System::Logging(__FUNCTION__);

        if(_once == false) {
            _once = true;
            _getter();
        }
        _once = false;
        return _value;
    }
};

template<>
class Property<Bool> : public Boolean {
public:
    typedef std::function<void(void)> Functor;
    static inline const Functor _functor = []() -> void {};

public:
    Bool _value = _None;
    Functor _setter;
    Functor _getter;
    bool _once = false;

public:
    explicit Property(const Bool& value = (Bool)"None", const Functor& setter = _functor, const Functor& getter = _functor) {
        System::Logging("explicit Property(const Bool& value = (Bool)"None", const Functor& setter = _functor, const Functor& getter = _functor) {");
        _value = value;
        _setter = setter;
        _getter = getter;
    }

    explicit Property(const bool& value = bool(), const Functor& setter = _functor, const Functor& getter = _functor) {
        System::Logging("explicit Property(const bool& value = bool(), const Functor& setter = _functor, const Functor& getter = _functor) {");
        _value = (value == true) ? _Posi : _Nega;
        _setter = setter;
        _getter = getter;
    }

    Bool& operator=(const Bool& value) {
        // System::Logging("Bool &operator=(const Bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _setter();
        }
        _once = false;
        return _value;
    }

    Bool& operator=(const bool& value) {
        // System::Logging("Bool &operator=(const bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = (value == true) ? _Posi : _Nega;
            _setter();
        }
        _once = false;
        return _value;
    }

    operator Bool& () {
        // System::Logging(__FUNCTION__);
        if(_once == false) {
            _once = true;
            _getter();
        }
        _once = false;
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
            Construct(address, objects[i]); address += sizeof(TAddress);
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
    std::set<std::vector<Class*>*> _set;

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
                _set.erase(_pointers);
                delete _pointers;
            }
        }
    }

public:
    Clean& Auto_Pointer(void* pointer) {
        System::Logging(__FUNCTION__);

        if (_pointers == nullptr) {
            _pointers = new std::vector<Class*>();
            _set.insert(_pointers);
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

template<typename TType>
void Delete(TType *&type) {
    if(type == nullptr) {
        return ;
    }
    delete type;
    type = nullptr;
}

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

struct Enume {
public:
    iptr _index = 0;
    iptr _enume = 0;
    const char* _field = "";
    const char* _alias = "";

public:
    Enume() {
        // System::Logging("Enum() {");
    }

    Enume(Enume *base, iptr enume, const char* alias) {
        // System::Logging("Enume(Enume *base, iptr enume, const char* alias) {");

        _index = base->_index;
        _enume = enume;
        _alias = alias;
        base->_index += 1;
    }

    Enume(Enume *base, const char* field, const char* alias) {
        // System::Logging("Enume(Enume *base, const char* field, const char* alias) {");

        _index = base->_index;
        _field = field;
        _alias = alias;
        base->_index += 1;
    }

    Enume(Enume *base, iptr enume, const char *field, const char *alias) {
        // System::Logging("Enume(Enume *base, iptr enume, const char *field, const char *alias) {");

        _index = base->_index;
        _enume = enume;
        _field = field;
        _alias = alias;
        base->_index += 1;
    }

public:
    Enume &operator[](iptr idx) {
        // System::Logging(__FUNCTION__);

        return ((Enume*)this)[idx + 1];
    }

public:
    QStringList _Aliases() {
        // System::Logging(__FUNCTION__);

        QStringList aliases = QStringList();
        Enume *base = (Enume *)this + 1;
        for(iptr idx = 0; idx < _index; idx += 1) {
            aliases.append(base[idx]._alias);
        }
        return aliases;
    }

    const char *_Alias(iptr enume) {
        // System::Logging(__FUNCTION__);

        Enume *base = (Enume *)this + 1;
        for(iptr idx = 0; idx < _index; idx += 1) {
            if(base[idx]._enume == enume) {
                return base[idx]._alias;
            }
        }
        return "";
    }

    iptr _Index(iptr enume) {
        // System::Logging(__FUNCTION__);

        Enume *base = (Enume *)this + 1;
        for(iptr idx = 0; idx < _index; idx += 1) {
            if(base[idx]._enume == enume) {
                return idx;
            }
        }
        return -1;
    }

    iptr _Enume(QString alias) {
        // System::Logging(__FUNCTION__);

        Enume *base = (Enume *)this + 1;
        for(iptr idx = 0; idx < _index; idx += 1) {
            if(base[idx]._alias == alias) {
                return base[idx]._enume;
            }
        }
        return -1;
    }
};

template<typename Field>
struct Enumeration {
public:
    Field &operator[](iptr idx) {
        // System::Logging(__FUNCTION__);

        return ((Field*)this)[idx + 1];
    }
};

static struct : public Enume {
    // Enume _None                             = Enume(this, QEvent::None                            , "None"                            , "invalid event");
    Enume _Timer                            = Enume(this, QEvent::Timer                           , "Timer"                           , "timer event");
    Enume _MouseButtonPress                 = Enume(this, QEvent::MouseButtonPress                , "MouseButtonPress"                , "mouse button pressed");
    Enume _MouseButtonRelease               = Enume(this, QEvent::MouseButtonRelease              , "MouseButtonRelease"              , "mouse button released");
    Enume _MouseButtonDblClick              = Enume(this, QEvent::MouseButtonDblClick             , "MouseButtonDblClick"             , "mouse button double click");
    Enume _MouseMove                        = Enume(this, QEvent::MouseMove                       , "MouseMove"                       , "mouse move");
    Enume _KeyPress                         = Enume(this, QEvent::KeyPress                        , "KeyPress"                        , "key pressed");
    Enume _KeyRelease                       = Enume(this, QEvent::KeyRelease                      , "KeyRelease"                      , "key released");
    Enume _FocusIn                          = Enume(this, QEvent::FocusIn                         , "FocusIn"                         , "keyboard focus received");
    Enume _FocusOut                         = Enume(this, QEvent::FocusOut                        , "FocusOut"                        , "keyboard focus lost");
    Enume _FocusAboutToChange               = Enume(this, QEvent::FocusAboutToChange              , "FocusAboutToChange"              , "keyboard focus is about to be lost");
    Enume _Enter                            = Enume(this, QEvent::Enter                           , "Enter"                           , "mouse enters widget");
    Enume _Leave                            = Enume(this, QEvent::Leave                           , "Leave"                           , "mouse leaves widget");
    Enume _Paint                            = Enume(this, QEvent::Paint                           , "Paint"                           , "paint widget");
    Enume _Move                             = Enume(this, QEvent::Move                            , "Move"                            , "move widget");
    Enume _Resize                           = Enume(this, QEvent::Resize                          , "Resize"                          , "resize widget");
    Enume _Create                           = Enume(this, QEvent::Create                          , "Create"                          , "after widget creation");
    Enume _Destroy                          = Enume(this, QEvent::Destroy                         , "Destroy"                         , "during widget destruction");
    Enume _Show                             = Enume(this, QEvent::Show                            , "Show"                            , "widget is shown");
    Enume _Hide                             = Enume(this, QEvent::Hide                            , "Hide"                            , "widget is hidden");
    Enume _Close                            = Enume(this, QEvent::Close                           , "Close"                           , "request to close widget");
    Enume _Quit                             = Enume(this, QEvent::Quit                            , "Quit"                            , "request to quit application");
    Enume _ParentChange                     = Enume(this, QEvent::ParentChange                    , "ParentChange"                    , "widget has been reparented");
    Enume _ParentAboutToChange              = Enume(this, QEvent::ParentAboutToChange             , "ParentAboutToChange"             , "sent just before the parent change is done");
    Enume _ThreadChange                     = Enume(this, QEvent::ThreadChange                    , "ThreadChange"                    , "object has changed threads");
    Enume _WindowActivate                   = Enume(this, QEvent::WindowActivate                  , "WindowActivate"                  , "window was activated");
    Enume _WindowDeactivate                 = Enume(this, QEvent::WindowDeactivate                , "WindowDeactivate"                , "window was deactivated");
    Enume _ShowToParent                     = Enume(this, QEvent::ShowToParent                    , "ShowToParent"                    , "widget is shown to parent");
    Enume _HideToParent                     = Enume(this, QEvent::HideToParent                    , "HideToParent"                    , "widget is hidden to parent");
    Enume _Wheel                            = Enume(this, QEvent::Wheel                           , "Wheel"                           , "wheel event");
    Enume _WindowTitleChange                = Enume(this, QEvent::WindowTitleChange               , "WindowTitleChange"               , "window title changed");
    Enume _WindowIconChange                 = Enume(this, QEvent::WindowIconChange                , "WindowIconChange"                , "icon changed");
    Enume _ApplicationWindowIconChange      = Enume(this, QEvent::ApplicationWindowIconChange     , "ApplicationWindowIconChange"     , "application icon changed");
    Enume _ApplicationFontChange            = Enume(this, QEvent::ApplicationFontChange           , "ApplicationFontChange"           , "application font changed");
    Enume _ApplicationLayoutDirectionChange = Enume(this, QEvent::ApplicationLayoutDirectionChange, "ApplicationLayoutDirectionChange", "application layout direction changed");
    Enume _ApplicationPaletteChange         = Enume(this, QEvent::ApplicationPaletteChange        , "ApplicationPaletteChange"        , "application palette changed");
    Enume _PaletteChange                    = Enume(this, QEvent::PaletteChange                   , "PaletteChange"                   , "widget palette changed");
    Enume _Clipboard                        = Enume(this, QEvent::Clipboard                       , "Clipboard"                       , "internal clipboard event");
    Enume _Speech                           = Enume(this, QEvent::Speech                          , "Speech"                          , "reserved for speech input");
    Enume _MetaCall                         = Enume(this, QEvent::MetaCall                        , "MetaCall"                        , "meta call event");
    Enume _SockAct                          = Enume(this, QEvent::SockAct                         , "SockAct"                         , "socket activation");
    Enume _WinEventAct                      = Enume(this, QEvent::WinEventAct                     , "WinEventAct"                     , "win event activation");
    Enume _DeferredDelete                   = Enume(this, QEvent::DeferredDelete                  , "DeferredDelete"                  , "deferred delete event");
    Enume _DragEnter                        = Enume(this, QEvent::DragEnter                       , "DragEnter"                       , "drag moves into widget");
    Enume _DragMove                         = Enume(this, QEvent::DragMove                        , "DragMove"                        , "drag moves in widget");
    Enume _DragLeave                        = Enume(this, QEvent::DragLeave                       , "DragLeave"                       , "drag leaves or is cancelled");
    Enume _Drop                             = Enume(this, QEvent::Drop                            , "Drop"                            , "actual drop");
    Enume _DragResponse                     = Enume(this, QEvent::DragResponse                    , "DragResponse"                    , "drag accepted/rejected");
    Enume _ChildAdded                       = Enume(this, QEvent::ChildAdded                      , "ChildAdded"                      , "new child widget");
    Enume _ChildPolished                    = Enume(this, QEvent::ChildPolished                   , "ChildPolished"                   , "polished child widget");
    Enume _ChildRemoved                     = Enume(this, QEvent::ChildRemoved                    , "ChildRemoved"                    , "deleted child widget");
    Enume _ShowWindowRequest                = Enume(this, QEvent::ShowWindowRequest               , "ShowWindowRequest"               , "widget's window should be mapped");
    Enume _PolishRequest                    = Enume(this, QEvent::PolishRequest                   , "PolishRequest"                   , "widget should be polished");
    Enume _Polish                           = Enume(this, QEvent::Polish                          , "Polish"                          , "widget is polished");
    Enume _LayoutRequest                    = Enume(this, QEvent::LayoutRequest                   , "LayoutRequest"                   , "widget should be relayouted");
    Enume _UpdateRequest                    = Enume(this, QEvent::UpdateRequest                   , "UpdateRequest"                   , "widget should be repainted");
    Enume _UpdateLater                      = Enume(this, QEvent::UpdateLater                     , "UpdateLater"                     , "request update() later");
    Enume _EmbeddingControl                 = Enume(this, QEvent::EmbeddingControl                , "EmbeddingControl"                , "ActiveX embedding");
    Enume _ActivateControl                  = Enume(this, QEvent::ActivateControl                 , "ActivateControl"                 , "ActiveX activation");
    Enume _DeactivateControl                = Enume(this, QEvent::DeactivateControl               , "DeactivateControl"               , "ActiveX deactivation");
    Enume _ContextMenu                      = Enume(this, QEvent::ContextMenu                     , "ContextMenu"                     , "context popup menu");
    Enume _InputMethod                      = Enume(this, QEvent::InputMethod                     , "InputMethod"                     , "input method");
    Enume _TabletMove                       = Enume(this, QEvent::TabletMove                      , "TabletMove"                      , "Wacom tablet event");
    Enume _LocaleChange                     = Enume(this, QEvent::LocaleChange                    , "LocaleChange"                    , "the system locale changed");
    Enume _LanguageChange                   = Enume(this, QEvent::LanguageChange                  , "LanguageChange"                  , "the application language changed");
    Enume _LayoutDirectionChange            = Enume(this, QEvent::LayoutDirectionChange           , "LayoutDirectionChange"           , "the layout direction changed");
    Enume _Style                            = Enume(this, QEvent::Style                           , "Style"                           , "internal style event");
    Enume _TabletPress                      = Enume(this, QEvent::TabletPress                     , "TabletPress"                     , "tablet press");
    Enume _TabletRelease                    = Enume(this, QEvent::TabletRelease                   , "TabletRelease"                   , "tablet release");
    Enume _OkRequest                        = Enume(this, QEvent::OkRequest                       , "OkRequest"                       , "CE (Ok) button pressed");
    Enume _HelpRequest                      = Enume(this, QEvent::HelpRequest                     , "HelpRequest"                     , "CE (?)  button pressed");
    Enume _IconDrag                         = Enume(this, QEvent::IconDrag                        , "IconDrag"                        , "proxy icon dragged");
    Enume _FontChange                       = Enume(this, QEvent::FontChange                      , "FontChange"                      , "font has changed");
    Enume _EnabledChange                    = Enume(this, QEvent::EnabledChange                   , "EnabledChange"                   , "enabled state has changed");
    Enume _ActivationChange                 = Enume(this, QEvent::ActivationChange                , "ActivationChange"                , "window activation has changed");
    Enume _StyleChange                      = Enume(this, QEvent::StyleChange                     , "StyleChange"                     , "style has changed");
    Enume _IconTextChange                   = Enume(this, QEvent::IconTextChange                  , "IconTextChange"                  , "icon text has changed.  Deprecated.");
    Enume _ModifiedChange                   = Enume(this, QEvent::ModifiedChange                  , "ModifiedChange"                  , "modified state has changed");
    Enume _MouseTrackingChange              = Enume(this, QEvent::MouseTrackingChange             , "MouseTrackingChange"             , "mouse tracking state has changed");
    Enume _WindowBlocked                    = Enume(this, QEvent::WindowBlocked                   , "WindowBlocked"                   , "window is about to be blocked modally");
    Enume _WindowUnblocked                  = Enume(this, QEvent::WindowUnblocked                 , "WindowUnblocked"                 , "windows modal blocking has ended");
    Enume _WindowStateChange                = Enume(this, QEvent::WindowStateChange               , "WindowStateChange"               , "");
    Enume _ReadOnlyChange                   = Enume(this, QEvent::ReadOnlyChange                  , "ReadOnlyChange"                  , "readonly state has changed");
    Enume _ToolTip                          = Enume(this, QEvent::ToolTip                         , "ToolTip"                         , "");
    Enume _WhatsThis                        = Enume(this, QEvent::WhatsThis                       , "WhatsThis"                       , "");
    Enume _StatusTip                        = Enume(this, QEvent::StatusTip                       , "StatusTip"                       , "");
    Enume _ActionChanged                    = Enume(this, QEvent::ActionChanged                   , "ActionChanged"                   , "");
    Enume _ActionAdded                      = Enume(this, QEvent::ActionAdded                     , "ActionAdded"                     , "");
    Enume _ActionRemoved                    = Enume(this, QEvent::ActionRemoved                   , "ActionRemoved"                   , "");
    Enume _FileOpen                         = Enume(this, QEvent::FileOpen                        , "FileOpen"                        , "file open request");
    Enume _Shortcut                         = Enume(this, QEvent::Shortcut                        , "Shortcut"                        , "shortcut triggered");
    Enume _ShortcutOverride                 = Enume(this, QEvent::ShortcutOverride                , "ShortcutOverride"                , "shortcut override request");
    Enume _WhatsThisClicked                 = Enume(this, QEvent::WhatsThisClicked                , "WhatsThisClicked"                , "");
    Enume _ToolBarChange                    = Enume(this, QEvent::ToolBarChange                   , "ToolBarChange"                   , "toolbar visibility toggled");
    Enume _ApplicationActivate              = Enume(this, QEvent::ApplicationActivate             , "ApplicationActivate"             , "deprecated. Use ApplicationStateChange instead.");
    Enume _ApplicationActivated             = Enume(this, QEvent::ApplicationActivated            , "ApplicationActivated"            , "deprecated");
    Enume _ApplicationDeactivate            = Enume(this, QEvent::ApplicationDeactivate           , "ApplicationDeactivate"           , "deprecated. Use ApplicationStateChange instead.");
    Enume _ApplicationDeactivated           = Enume(this, QEvent::ApplicationDeactivated          , "ApplicationDeactivated"          , "deprecated");
    Enume _QueryWhatsThis                   = Enume(this, QEvent::QueryWhatsThis                  , "QueryWhatsThis"                  , "query what's this widget help");
    Enume _EnterWhatsThisMode               = Enume(this, QEvent::EnterWhatsThisMode              , "EnterWhatsThisMode"              , "");
    Enume _LeaveWhatsThisMode               = Enume(this, QEvent::LeaveWhatsThisMode              , "LeaveWhatsThisMode"              , "");
    Enume _ZOrderChange                     = Enume(this, QEvent::ZOrderChange                    , "ZOrderChange"                    , "child widget has had its z-order changed");
    Enume _HoverEnter                       = Enume(this, QEvent::HoverEnter                      , "HoverEnter"                      , "mouse cursor enters a hover widget");
    Enume _HoverLeave                       = Enume(this, QEvent::HoverLeave                      , "HoverLeave"                      , "mouse cursor leaves a hover widget");
    Enume _HoverMove                        = Enume(this, QEvent::HoverMove                       , "HoverMove"                       , "mouse cursor move inside a hover widget");
#ifdef    QT_KEYPAD_NAVIGATION
    Enume _EnterEditFocus                   = Enume(this, QEvent::EnterEditFocus                  , "EnterEditFocus"                  , "enter edit mode in keypad navigation");
    Enume _LeaveEditFocus                   = Enume(this, QEvent::LeaveEditFocus                  , "LeaveEditFocus"                  , "enter edit mode in keypad navigation");
#endif // QT_KEYPAD_NAVIGATION
    Enume _AcceptDropsChange                = Enume(this, QEvent::AcceptDropsChange               , "AcceptDropsChange"               , "");
    Enume _ZeroTimerEvent                   = Enume(this, QEvent::ZeroTimerEvent                  , "ZeroTimerEvent"                  , "Used for Windows Zero timer events");
    Enume _GraphicsSceneMouseMove           = Enume(this, QEvent::GraphicsSceneMouseMove          , "GraphicsSceneMouseMove"          , "GraphicsView");
    Enume _GraphicsSceneMousePress          = Enume(this, QEvent::GraphicsSceneMousePress         , "GraphicsSceneMousePress"         , "");
    Enume _GraphicsSceneMouseRelease        = Enume(this, QEvent::GraphicsSceneMouseRelease       , "GraphicsSceneMouseRelease"       , "");
    Enume _GraphicsSceneMouseDoubleClick    = Enume(this, QEvent::GraphicsSceneMouseDoubleClick   , "GraphicsSceneMouseDoubleClick"   , "");
    Enume _GraphicsSceneContextMenu         = Enume(this, QEvent::GraphicsSceneContextMenu        , "GraphicsSceneContextMenu"        , "");
    Enume _GraphicsSceneHoverEnter          = Enume(this, QEvent::GraphicsSceneHoverEnter         , "GraphicsSceneHoverEnter"         , "");
    Enume _GraphicsSceneHoverMove           = Enume(this, QEvent::GraphicsSceneHoverMove          , "GraphicsSceneHoverMove"          , "");
    Enume _GraphicsSceneHoverLeave          = Enume(this, QEvent::GraphicsSceneHoverLeave         , "GraphicsSceneHoverLeave"         , "");
    Enume _GraphicsSceneHelp                = Enume(this, QEvent::GraphicsSceneHelp               , "GraphicsSceneHelp"               , "");
    Enume _GraphicsSceneDragEnter           = Enume(this, QEvent::GraphicsSceneDragEnter          , "GraphicsSceneDragEnter"          , "");
    Enume _GraphicsSceneDragMove            = Enume(this, QEvent::GraphicsSceneDragMove           , "GraphicsSceneDragMove"           , "");
    Enume _GraphicsSceneDragLeave           = Enume(this, QEvent::GraphicsSceneDragLeave          , "GraphicsSceneDragLeave"          , "");
    Enume _GraphicsSceneDrop                = Enume(this, QEvent::GraphicsSceneDrop               , "GraphicsSceneDrop"               , "");
    Enume _GraphicsSceneWheel               = Enume(this, QEvent::GraphicsSceneWheel              , "GraphicsSceneWheel"              , "");
    Enume _KeyboardLayoutChange             = Enume(this, QEvent::KeyboardLayoutChange            , "KeyboardLayoutChange"            , "keyboard layout changed");
    Enume _DynamicPropertyChange            = Enume(this, QEvent::DynamicPropertyChange           , "DynamicPropertyChange"           , "A dynamic property was changed through setProperty/property");
    Enume _TabletEnterProximity             = Enume(this, QEvent::TabletEnterProximity            , "TabletEnterProximity"            , "");
    Enume _TabletLeaveProximity             = Enume(this, QEvent::TabletLeaveProximity            , "TabletLeaveProximity"            , "");
    Enume _NonClientAreaMouseMove           = Enume(this, QEvent::NonClientAreaMouseMove          , "NonClientAreaMouseMove"          , "");
    Enume _NonClientAreaMouseButtonPress    = Enume(this, QEvent::NonClientAreaMouseButtonPress   , "NonClientAreaMouseButtonPress"   , "");
    Enume _NonClientAreaMouseButtonRelease  = Enume(this, QEvent::NonClientAreaMouseButtonRelease , "NonClientAreaMouseButtonRelease" , "");
    Enume _NonClientAreaMouseButtonDblClick = Enume(this, QEvent::NonClientAreaMouseButtonDblClick, "NonClientAreaMouseButtonDblClick", "");
    Enume _MacSizeChange                    = Enume(this, QEvent::MacSizeChange                   , "MacSizeChange"                   , "when the Qt::WA_Mac{Normal,Small,Mini}Size changes");
    Enume _ContentsRectChange               = Enume(this, QEvent::ContentsRectChange              , "ContentsRectChange"              , "sent by QWidget::setContentsMargins (internal)");
    Enume _MacGLWindowChange                = Enume(this, QEvent::MacGLWindowChange               , "MacGLWindowChange"               , "Internal! the window of the GLWidget has changed");
    Enume _FutureCallOut                    = Enume(this, QEvent::FutureCallOut                   , "FutureCallOut"                   , "");
    Enume _GraphicsSceneResize              = Enume(this, QEvent::GraphicsSceneResize             , "GraphicsSceneResize"             , "");
    Enume _GraphicsSceneMove                = Enume(this, QEvent::GraphicsSceneMove               , "GraphicsSceneMove"               , "");
    Enume _CursorChange                     = Enume(this, QEvent::CursorChange                    , "CursorChange"                    , "");
    Enume _ToolTipChange                    = Enume(this, QEvent::ToolTipChange                   , "ToolTipChange"                   , "");
    Enume _NetworkReplyUpdated              = Enume(this, QEvent::NetworkReplyUpdated             , "NetworkReplyUpdated"             , "Internal for QNetworkReply");
    Enume _GrabMouse                        = Enume(this, QEvent::GrabMouse                       , "GrabMouse"                       , "");
    Enume _UngrabMouse                      = Enume(this, QEvent::UngrabMouse                     , "UngrabMouse"                     , "");
    Enume _GrabKeyboard                     = Enume(this, QEvent::GrabKeyboard                    , "GrabKeyboard"                    , "");
    Enume _UngrabKeyboard                   = Enume(this, QEvent::UngrabKeyboard                  , "UngrabKeyboard"                  , "");
    Enume _MacGLClearDrawable               = Enume(this, QEvent::MacGLClearDrawable              , "MacGLClearDrawable"              , "Internal Cocoa, the window has changed, so we must clear");
    Enume _StateMachineSignal               = Enume(this, QEvent::StateMachineSignal              , "StateMachineSignal"              , "");
    Enume _StateMachineWrapped              = Enume(this, QEvent::StateMachineWrapped             , "StateMachineWrapped"             , "");
    Enume _TouchBegin                       = Enume(this, QEvent::TouchBegin                      , "TouchBegin"                      , "");
    Enume _TouchUpdate                      = Enume(this, QEvent::TouchUpdate                     , "TouchUpdate"                     , "");
    Enume _TouchEnd                         = Enume(this, QEvent::TouchEnd                        , "TouchEnd"                        , "");
    Enume _NativeGesture                    = Enume(this, QEvent::NativeGesture                   , "NativeGesture"                   , "QtGui native gesture");
    Enume _RequestSoftwareInputPanel        = Enume(this, QEvent::RequestSoftwareInputPanel       , "RequestSoftwareInputPanel"       , "");
    Enume _CloseSoftwareInputPanel          = Enume(this, QEvent::CloseSoftwareInputPanel         , "CloseSoftwareInputPanel"         , "");
    Enume _WinIdChange                      = Enume(this, QEvent::WinIdChange                     , "WinIdChange"                     , "");
    Enume _Gesture                          = Enume(this, QEvent::Gesture                         , "Gesture"                         , "");
    Enume _GestureOverride                  = Enume(this, QEvent::GestureOverride                 , "GestureOverride"                 , "");
    Enume _ScrollPrepare                    = Enume(this, QEvent::ScrollPrepare                   , "ScrollPrepare"                   , "");
    Enume _Scroll                           = Enume(this, QEvent::Scroll                          , "Scroll"                          , "");
    Enume _Expose                           = Enume(this, QEvent::Expose                          , "Expose"                          , "");
    Enume _InputMethodQuery                 = Enume(this, QEvent::InputMethodQuery                , "InputMethodQuery"                , "");
    Enume _OrientationChange                = Enume(this, QEvent::OrientationChange               , "OrientationChange"               , "Screen orientation has changed");
    Enume _TouchCancel                      = Enume(this, QEvent::TouchCancel                     , "TouchCancel"                     , "");
    Enume _ThemeChange                      = Enume(this, QEvent::ThemeChange                     , "ThemeChange"                     , "");
    Enume _SockClose                        = Enume(this, QEvent::SockClose                       , "SockClose"                       , "socket closed");
    Enume _PlatformPanel                    = Enume(this, QEvent::PlatformPanel                   , "PlatformPanel"                   , "");
    Enume _StyleAnimationUpdate             = Enume(this, QEvent::StyleAnimationUpdate            , "StyleAnimationUpdate"            , "style animation target should be updated");
    Enume _ApplicationStateChange           = Enume(this, QEvent::ApplicationStateChange          , "ApplicationStateChange"          , "");
    Enume _WindowChangeInternal             = Enume(this, QEvent::WindowChangeInternal            , "WindowChangeInternal"            , "internal for QQuickWidget");
    Enume _ScreenChangeInternal             = Enume(this, QEvent::ScreenChangeInternal            , "ScreenChangeInternal"            , "");
    Enume _PlatformSurface                  = Enume(this, QEvent::PlatformSurface                 , "PlatformSurface"                 , "Platform surface created or about to be destroyed");
    Enume _Pointer                          = Enume(this, QEvent::Pointer                         , "Pointer"                         , "QQuickPointerEvent; ### Qt 6: QPointerEvent");
    Enume _TabletTrackingChange             = Enume(this, QEvent::TabletTrackingChange            , "TabletTrackingChange"            , "tablet tracking state has changed");
    Enume _User                             = Enume(this, QEvent::User                            , "User"                            , "first user event id");
    Enume _MaxUser                          = Enume(this, QEvent::MaxUser                         , "MaxUser"                         , "last user event id");
} _event_type;

struct State : Enume {
    Enume _Created = Enume(this, 0x01, "Created");
    Enume _Running = Enume(this, 0x02, "Running");
    Enume _Waiting = Enume(this, 0x04, "Waiting");
    Enume _Stopped = Enume(this, 0x08, "Stopped");
};

////////////////////////////////////////////////////////////////////////////////

/* Y-Z coordinate to X-Y coordinate
                                [x_max, y_min]
   [x_min, y_min]  [Y_MAX==x_max-x_min, Z_MAX==y_max-y_min]
        o+----------------------------+
         |                            |
         |      +-----+               |
         |      |     |               |
         |     Q+-----+               |
         |    [Y, Z]                  |
         |                            |
        P+----------------------------+
[Y_MIN==0, Z_MIN==0]               [x_max, y_max]
   [x_min, y_max]

        vector[oq] = vector[op]         + vector[pq]
[q_x-o_x, q_y-o_y] = [p_x-o_x, p_y-o_y] + [q_x-p_x, q_y-p_y]
[x-x_min, y-y_min] = [0, y_max-y_min]   + [x-x_min, y-y_max]
        vector[oQ] = vector[oP]         + vector[PQ]
        vector[oq] = vector[op]         + vector[PQ]
[x-x_min, y-y_min] = [0, y_max-y_min]   + [Y-Y_MIN, -(Z-Z_MIN)]
[x-x_min, y-y_min] = [0, y_max-y_min]   + [Y, -Z]
            [x, y] = [Y+x_min, y_max-Z]
*/

struct Area {
public:
    iptr _X_Min = 0;
    iptr _Y_Min = 0;
    iptr _X_Max = 0;
    iptr _Y_Max = 0;

public:
    iptr _x_min = 0;
    iptr _y_min = 0;
    iptr _x_max = 0;
    iptr _y_max = 0;

public:
    Area(iptr X_From, iptr Y_From, iptr X_Upto, iptr Y_Upto) {
        System::Logging(__FUNCTION__);

        if(X_From < X_Upto) {
            _X_Min = X_From;
            _X_Max = X_Upto;
        } else {
            _X_Min = X_Upto;
            _X_Max = X_From;
        }
        if(Y_From < Y_Upto) {
            _Y_Min = Y_From;
            _Y_Max = Y_Upto;
        } else {
            _Y_Min = Y_Upto;
            _Y_Max = Y_From;
        }
    }

    operator QRect() {
        System::Logging(__FUNCTION__);

        return QRect(_X_Min, _Y_Min, _X_Max - _X_Min, _Y_Max - _Y_Min);
    }

public:
    static QRect _Viewport(iptr x_from, iptr y_from, iptr x_upto, iptr y_upto, double ratio) {
        System::Logging(__FUNCTION__);

        iptr x_min = 0;
        iptr y_min = 0;
        iptr x_max = 0;
        iptr y_max = 0;
        if(x_from < x_upto) {
            x_min = x_from;
            x_max = x_upto;
        } else {
            x_min = x_upto;
            x_max = x_from;
        }
        if(y_from < y_upto) {
            y_min = y_from;
            y_max = y_upto;
        } else {
            y_min = y_upto;
            y_max = y_from;
        }

        iptr width = x_max - x_min;
        iptr height = y_max - y_min;
        if(width * ratio < height) {
            height = width * ratio;
        } else {
            width = height / ratio;
        }

        return QRect((x_min + x_max - width) / 2, (y_min + y_max - height) / 2, width, height);
    }

    static QRect _Proption(QRect rect, double prop) {
        System::Logging(__FUNCTION__);

        return QRect(rect.x() * prop, rect.y() * prop, rect.width() * prop, rect.height() * prop);
    }

public:
    QRect _XY_Rect(iptr x_from, iptr y_from, iptr x_upto, iptr y_upto, iptr border = 0) {
        System::Logging(__FUNCTION__);

        if(x_from < x_upto) {
            _x_min = x_from;
            _x_max = x_upto;
        } else {
            _x_min = x_upto;
            _x_max = x_from;
        }
        if(y_from < y_upto) {
            _y_min = y_from;
            _y_max = y_upto;
        } else {
            _y_min = y_upto;
            _y_max = y_from;
        }
        border /= 2;
        _x_min += border;
        _y_min += border;
        _x_max -= border;
        _y_max -= border;
        return QRect(_x_min, _y_min, _x_max - _x_min, _y_max - _y_min);
    }

    QRect _YZ_Rect(iptr Y_FROM, iptr Z_FROM, iptr Y_UPTO, iptr Z_UPTO, iptr BORDER = 0) {
        System::Logging(__FUNCTION__);

        iptr x_from = Y_FROM + _X_Min;
        iptr y_from = _Y_Max - Z_FROM;
        iptr x_upto = Y_UPTO + _X_Min;
        iptr y_upto = _Y_Max - Z_UPTO;

        if(x_from < x_upto) {
            _x_min = x_from;
            _x_max = x_upto;
        } else {
            _x_min = x_upto;
            _x_max = x_from;
        }
        if(y_from < y_upto) {
            _y_min = y_from;
            _y_max = y_upto;
        } else {
            _y_min = y_upto;
            _y_max = y_from;
        }
        BORDER /= 2;
        _x_min += BORDER;
        _y_min += BORDER;
        _x_max -= BORDER;
        _y_max -= BORDER;

        System::Logging("[%d, %d, %d, %d]", _x_min, _y_min, _x_max, _y_max);
        return QRect(_x_min, _y_min, _x_max - _x_min, _y_max - _y_min);
    }

    QPoint _YZ_Point(iptr Y, iptr Z) {
        System::Logging(__FUNCTION__);

        iptr x = Y + _X_Min;
        iptr y = _Y_Max - Z;
        return QPoint(x, y);
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
