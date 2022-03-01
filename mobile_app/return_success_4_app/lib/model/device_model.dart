import 'package:isar/isar.dart';

part 'device_model.g.dart';

@Collection()
class Device {
  /// Isar ID required to be unique for each object
  @Id()
  int id = Isar.autoIncrement;

  /// Unique device ID used to indentify a physical device
  String deviceId;

  /// Topics to listen to for incoming notifications
  List<String> topics;

  /// Constructor of a Device object
  Device({
    required this.deviceId,
    required this.topics,
  });
}
