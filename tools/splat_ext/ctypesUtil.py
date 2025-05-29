import ctypes
from tools.splat_ext.vsString import vsStringBase, encode, decode


def ctypes_to_dict(obj):
    if isinstance(obj, vsStringBase):
        return decode(obj)
    if isinstance(obj, ctypes.Array):
        return [ctypes_to_dict(item) for item in obj]
    if hasattr(obj, "_fields_"):
        result = {}
        for field in obj._fields_:
            value = getattr(obj, field[0])
            result[field[0]] = ctypes_to_dict(value)
        return result
    return obj
    
def dict_to_ctypes(data, ctype):
    if issubclass(ctype, vsStringBase):
        return ctype(*encode(data))
    if issubclass(ctype, ctypes.Array):
        arr = ctype()
        for i, item in enumerate(data):
            arr[i] = dict_to_ctypes(item, ctype._type_)
        return arr
    if hasattr(ctype, "_fields_"):
        inst = ctype()
        for field in ctype._fields_:
            name = field[0]
            value = data[name]
            setattr(inst, name, dict_to_ctypes(value, field[1]))
        return inst
    return data

def dict_to_c_initializer(data, ctype):
    if issubclass(ctype, vsStringBase):
        return '"' + data.encode("unicode_escape").decode('utf8') + '"'
    if issubclass(ctype, ctypes.Array):
        items = [dict_to_c_initializer(item, ctype._type_) for item in data]
        return '{' + ', '.join(items) + '}'
    if hasattr(ctype, "_fields_"):
        fields = []
        for field in ctype._fields_:
            name = field[0]
            field_type = field[1]
            value = data[name]
            fields.append(f'.{name} = {dict_to_c_initializer(value, field_type)}')
        return '{' + ', '.join(fields) + '}'
    return str(data)
