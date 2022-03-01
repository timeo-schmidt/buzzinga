// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'device_model.dart';

// **************************************************************************
// IsarCollectionGenerator
// **************************************************************************

// ignore_for_file: duplicate_ignore, non_constant_identifier_names, invalid_use_of_protected_member, unnecessary_cast

extension GetDeviceCollection on Isar {
  IsarCollection<Device> get devices {
    return getCollection('Device');
  }
}

final DeviceSchema = CollectionSchema(
  name: 'Device',
  schema:
      '{"name":"Device","idName":"id","properties":[{"name":"deviceId","type":"String"},{"name":"topics","type":"StringList"}],"indexes":[],"links":[]}',
  nativeAdapter: const _DeviceNativeAdapter(),
  webAdapter: const _DeviceWebAdapter(),
  idName: 'id',
  propertyIds: {'deviceId': 0, 'topics': 1},
  listProperties: {'topics'},
  indexIds: {},
  indexTypes: {},
  linkIds: {},
  backlinkIds: {},
  linkedCollections: [],
  getId: (obj) {
    if (obj.id == Isar.autoIncrement) {
      return null;
    } else {
      return obj.id;
    }
  },
  setId: (obj, id) => obj.id = id,
  getLinks: (obj) => [],
  version: 2,
);

class _DeviceWebAdapter extends IsarWebTypeAdapter<Device> {
  const _DeviceWebAdapter();

  @override
  Object serialize(IsarCollection<Device> collection, Device object) {
    final jsObj = IsarNative.newJsObject();
    IsarNative.jsObjectSet(jsObj, 'deviceId', object.deviceId);
    IsarNative.jsObjectSet(jsObj, 'id', object.id);
    IsarNative.jsObjectSet(jsObj, 'topics', object.topics);
    return jsObj;
  }

  @override
  Device deserialize(IsarCollection<Device> collection, dynamic jsObj) {
    final object = Device(
      deviceId: IsarNative.jsObjectGet(jsObj, 'deviceId') ?? '',
      topics: (IsarNative.jsObjectGet(jsObj, 'topics') as List?)
              ?.map((e) => e ?? '')
              .toList()
              .cast<String>() ??
          [],
    );
    object.id = IsarNative.jsObjectGet(jsObj, 'id') ?? double.negativeInfinity;
    return object;
  }

  @override
  P deserializeProperty<P>(Object jsObj, String propertyName) {
    switch (propertyName) {
      case 'deviceId':
        return (IsarNative.jsObjectGet(jsObj, 'deviceId') ?? '') as P;
      case 'id':
        return (IsarNative.jsObjectGet(jsObj, 'id') ?? double.negativeInfinity)
            as P;
      case 'topics':
        return ((IsarNative.jsObjectGet(jsObj, 'topics') as List?)
                ?.map((e) => e ?? '')
                .toList()
                .cast<String>() ??
            []) as P;
      default:
        throw 'Illegal propertyName';
    }
  }

  @override
  void attachLinks(Isar isar, int id, Device object) {}
}

class _DeviceNativeAdapter extends IsarNativeTypeAdapter<Device> {
  const _DeviceNativeAdapter();

  @override
  void serialize(IsarCollection<Device> collection, IsarRawObject rawObj,
      Device object, int staticSize, List<int> offsets, AdapterAlloc alloc) {
    var dynamicSize = 0;
    final value0 = object.deviceId;
    final _deviceId = IsarBinaryWriter.utf8Encoder.convert(value0);
    dynamicSize += (_deviceId.length) as int;
    final value1 = object.topics;
    dynamicSize += (value1.length) * 8;
    final bytesList1 = <IsarUint8List>[];
    for (var str in value1) {
      final bytes = IsarBinaryWriter.utf8Encoder.convert(str);
      bytesList1.add(bytes);
      dynamicSize += bytes.length as int;
    }
    final _topics = bytesList1;
    final size = staticSize + dynamicSize;

    rawObj.buffer = alloc(size);
    rawObj.buffer_length = size;
    final buffer = IsarNative.bufAsBytes(rawObj.buffer, size);
    final writer = IsarBinaryWriter(buffer, staticSize);
    writer.writeBytes(offsets[0], _deviceId);
    writer.writeStringList(offsets[1], _topics);
  }

  @override
  Device deserialize(IsarCollection<Device> collection, int id,
      IsarBinaryReader reader, List<int> offsets) {
    final object = Device(
      deviceId: reader.readString(offsets[0]),
      topics: reader.readStringList(offsets[1]) ?? [],
    );
    object.id = id;
    return object;
  }

  @override
  P deserializeProperty<P>(
      int id, IsarBinaryReader reader, int propertyIndex, int offset) {
    switch (propertyIndex) {
      case -1:
        return id as P;
      case 0:
        return (reader.readString(offset)) as P;
      case 1:
        return (reader.readStringList(offset) ?? []) as P;
      default:
        throw 'Illegal propertyIndex';
    }
  }

  @override
  void attachLinks(Isar isar, int id, Device object) {}
}

extension DeviceQueryWhereSort on QueryBuilder<Device, Device, QWhere> {
  QueryBuilder<Device, Device, QAfterWhere> anyId() {
    return addWhereClauseInternal(const WhereClause(indexName: null));
  }
}

extension DeviceQueryWhere on QueryBuilder<Device, Device, QWhereClause> {
  QueryBuilder<Device, Device, QAfterWhereClause> idEqualTo(int id) {
    return addWhereClauseInternal(WhereClause(
      indexName: null,
      lower: [id],
      includeLower: true,
      upper: [id],
      includeUpper: true,
    ));
  }

  QueryBuilder<Device, Device, QAfterWhereClause> idNotEqualTo(int id) {
    if (whereSortInternal == Sort.asc) {
      return addWhereClauseInternal(WhereClause(
        indexName: null,
        upper: [id],
        includeUpper: false,
      )).addWhereClauseInternal(WhereClause(
        indexName: null,
        lower: [id],
        includeLower: false,
      ));
    } else {
      return addWhereClauseInternal(WhereClause(
        indexName: null,
        lower: [id],
        includeLower: false,
      )).addWhereClauseInternal(WhereClause(
        indexName: null,
        upper: [id],
        includeUpper: false,
      ));
    }
  }

  QueryBuilder<Device, Device, QAfterWhereClause> idGreaterThan(
    int id, {
    bool include = false,
  }) {
    return addWhereClauseInternal(WhereClause(
      indexName: null,
      lower: [id],
      includeLower: include,
    ));
  }

  QueryBuilder<Device, Device, QAfterWhereClause> idLessThan(
    int id, {
    bool include = false,
  }) {
    return addWhereClauseInternal(WhereClause(
      indexName: null,
      upper: [id],
      includeUpper: include,
    ));
  }

  QueryBuilder<Device, Device, QAfterWhereClause> idBetween(
    int lowerId,
    int upperId, {
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return addWhereClauseInternal(WhereClause(
      indexName: null,
      lower: [lowerId],
      includeLower: includeLower,
      upper: [upperId],
      includeUpper: includeUpper,
    ));
  }
}

extension DeviceQueryFilter on QueryBuilder<Device, Device, QFilterCondition> {
  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdEqualTo(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.eq,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdGreaterThan(
    String value, {
    bool caseSensitive = true,
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.gt,
      include: include,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdLessThan(
    String value, {
    bool caseSensitive = true,
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.lt,
      include: include,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdBetween(
    String lower,
    String upper, {
    bool caseSensitive = true,
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return addFilterConditionInternal(FilterCondition.between(
      property: 'deviceId',
      lower: lower,
      includeLower: includeLower,
      upper: upper,
      includeUpper: includeUpper,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdStartsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.startsWith,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdEndsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.endsWith,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdContains(
      String value,
      {bool caseSensitive = true}) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.contains,
      property: 'deviceId',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> deviceIdMatches(
      String pattern,
      {bool caseSensitive = true}) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.matches,
      property: 'deviceId',
      value: pattern,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> idEqualTo(int value) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.eq,
      property: 'id',
      value: value,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> idGreaterThan(
    int value, {
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.gt,
      include: include,
      property: 'id',
      value: value,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> idLessThan(
    int value, {
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.lt,
      include: include,
      property: 'id',
      value: value,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> idBetween(
    int lower,
    int upper, {
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return addFilterConditionInternal(FilterCondition.between(
      property: 'id',
      lower: lower,
      includeLower: includeLower,
      upper: upper,
      includeUpper: includeUpper,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyEqualTo(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.eq,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyGreaterThan(
    String value, {
    bool caseSensitive = true,
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.gt,
      include: include,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyLessThan(
    String value, {
    bool caseSensitive = true,
    bool include = false,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.lt,
      include: include,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyBetween(
    String lower,
    String upper, {
    bool caseSensitive = true,
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return addFilterConditionInternal(FilterCondition.between(
      property: 'topics',
      lower: lower,
      includeLower: includeLower,
      upper: upper,
      includeUpper: includeUpper,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyStartsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.startsWith,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyEndsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.endsWith,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyContains(
      String value,
      {bool caseSensitive = true}) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.contains,
      property: 'topics',
      value: value,
      caseSensitive: caseSensitive,
    ));
  }

  QueryBuilder<Device, Device, QAfterFilterCondition> topicsAnyMatches(
      String pattern,
      {bool caseSensitive = true}) {
    return addFilterConditionInternal(FilterCondition(
      type: ConditionType.matches,
      property: 'topics',
      value: pattern,
      caseSensitive: caseSensitive,
    ));
  }
}

extension DeviceQueryWhereSortBy on QueryBuilder<Device, Device, QSortBy> {
  QueryBuilder<Device, Device, QAfterSortBy> sortByDeviceId() {
    return addSortByInternal('deviceId', Sort.asc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> sortByDeviceIdDesc() {
    return addSortByInternal('deviceId', Sort.desc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> sortById() {
    return addSortByInternal('id', Sort.asc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> sortByIdDesc() {
    return addSortByInternal('id', Sort.desc);
  }
}

extension DeviceQueryWhereSortThenBy
    on QueryBuilder<Device, Device, QSortThenBy> {
  QueryBuilder<Device, Device, QAfterSortBy> thenByDeviceId() {
    return addSortByInternal('deviceId', Sort.asc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> thenByDeviceIdDesc() {
    return addSortByInternal('deviceId', Sort.desc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> thenById() {
    return addSortByInternal('id', Sort.asc);
  }

  QueryBuilder<Device, Device, QAfterSortBy> thenByIdDesc() {
    return addSortByInternal('id', Sort.desc);
  }
}

extension DeviceQueryWhereDistinct on QueryBuilder<Device, Device, QDistinct> {
  QueryBuilder<Device, Device, QDistinct> distinctByDeviceId(
      {bool caseSensitive = true}) {
    return addDistinctByInternal('deviceId', caseSensitive: caseSensitive);
  }

  QueryBuilder<Device, Device, QDistinct> distinctById() {
    return addDistinctByInternal('id');
  }
}

extension DeviceQueryProperty on QueryBuilder<Device, Device, QQueryProperty> {
  QueryBuilder<Device, String, QQueryOperations> deviceIdProperty() {
    return addPropertyNameInternal('deviceId');
  }

  QueryBuilder<Device, int, QQueryOperations> idProperty() {
    return addPropertyNameInternal('id');
  }

  QueryBuilder<Device, List<String>, QQueryOperations> topicsProperty() {
    return addPropertyNameInternal('topics');
  }
}
