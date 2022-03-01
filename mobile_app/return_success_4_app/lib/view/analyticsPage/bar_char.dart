import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:isar/isar.dart';
import 'package:return_success_4_app/model/message_model.dart';
import 'package:return_success_4_app/view/general_functions.dart';

/// A card displaying analytics on a chart, with a label.
class AnalyticsBarChart extends StatefulWidget {
  const AnalyticsBarChart(
      {required this.label,
      required this.category,
      required this.isar,
      this.colorProfile,
      required this.demoMode,
      Key? key})
      : super(key: key);

  final String label;
  final String category;
  final Isar isar;
  final List<Color>? colorProfile;
  final bool demoMode;

  @override
  State<StatefulWidget> createState() => AnalyticsBarChartState();
}

class AnalyticsBarChartState extends State<AnalyticsBarChart> {
  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.all(8),
        padding: const EdgeInsets.fromLTRB(6, 6, 6, 10),
        decoration: const BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.all(Radius.circular(20)),
          boxShadow: [
            BoxShadow(
              color: Color.fromARGB(25, 0, 0, 0),
              offset: Offset(2, 2),
              blurRadius: 8,
            ),
          ],
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(12, 10, 12, 40),
              child: Text(
                widget.label,
                style: const TextStyle(
                    color: Color.fromARGB(255, 70, 70, 70),
                    fontWeight: FontWeight.bold),
              ),
            ),
            AspectRatio(
              aspectRatio: 1.7,
              child: StreamBuilder(
                  stream: widget.isar.messages
                      .filter()
                      .categoryEqualTo(widget.category)
                      .watch(initialReturn: true),
                  builder: (BuildContext context,
                      AsyncSnapshot<List<Message>> snapshot) {
                    if (snapshot.hasData) {
                      // First initialize the data list with the offset of the
                      // month in the past that you want to isolate
                      List<double> data = [6, 5, 4, 3, 2, 1, 0];
                      // Then map the list with the filtering function
                      data = data
                          .map((value) => countMessageMatchMonth(
                              snapshot.data!, value.toInt()))
                          .toList();
                      // If in demo mode:
                      if (widget.demoMode && (widget.category == "Doorbell")) {
                        // Add large-scale dummy data to fill "Doorbell" graph
                        // [26, 31, 22, 37, 41, 32, 23]
                        data[0] += 26;
                        data[1] += 31;
                        data[2] += 22;
                        data[3] += 37;
                        data[4] += 41;
                        data[5] += 32;
                        data[6] += 23;
                      } else if (widget.demoMode &&
                          (widget.category == "Fire Alarm")) {
                        // Add large-scale dummy data to fill "Fire Alarm" graph
                        // [0, 1, 0, 2, 1, 1, 0]
                        data[1] += 1;
                        data[3] += 2;
                        data[4] += 1;
                        data[5] += 1;
                      }
                      return _BarChart(
                        data: data,
                        colorProfile: widget.colorProfile,
                      );
                    } else {
                      List<double> dataZero = [0, 0, 0, 0, 0, 0, 0];
                      return _BarChart(
                        data: dataZero,
                        colorProfile: widget.colorProfile,
                      );
                    }
                  }),
            )
          ],
        ));
  }
}

class _BarChart extends StatelessWidget {
  const _BarChart({required this.data, this.colorProfile, Key? key})
      : super(key: key);

  final List<double> data;
  final List<Color>? colorProfile;

  @override
  Widget build(BuildContext context) {
    double max = 0;
    for (double i in data) {
      if (i > max) max = i;
    }
    return BarChart(
      BarChartData(
        barTouchData: barTouchData,
        titlesData: titlesData,
        borderData: borderData,
        barGroups: barGroups,
        alignment: BarChartAlignment.spaceAround,
        gridData: FlGridData(show: false),
        maxY: max,
      ),
    );
  }

  BarTouchData get barTouchData => BarTouchData(
        enabled: false,
        touchTooltipData: BarTouchTooltipData(
          tooltipBgColor: Colors.transparent,
          tooltipPadding: const EdgeInsets.all(0),
          tooltipMargin: 8,
          getTooltipItem: (
            BarChartGroupData group,
            int groupIndex,
            BarChartRodData rod,
            int rodIndex,
          ) {
            return BarTooltipItem(
              rod.y.round().toString(),
              const TextStyle(
                color: Color.fromARGB(255, 71, 98, 131),
                fontWeight: FontWeight.bold,
              ),
            );
          },
        ),
      );

  FlTitlesData get titlesData => FlTitlesData(
        show: true,
        bottomTitles: SideTitles(
          showTitles: true,
          getTextStyles: (context, value) => const TextStyle(
            color: Color.fromARGB(255, 44, 63, 85),
            fontWeight: FontWeight.bold,
            fontSize: 14,
          ),
          margin: 20,
          getTitles: (double value) =>
              monthToWord(DateTime.now().month - 6 + value.toInt(), true),
        ),
        leftTitles: SideTitles(showTitles: false),
        topTitles: SideTitles(showTitles: false),
        rightTitles: SideTitles(showTitles: false),
      );

  FlBorderData get borderData => FlBorderData(
        show: false,
      );

  List<BarChartGroupData> get barGroups => [
        BarChartGroupData(
          x: 0,
          barRods: [
            BarChartRodData(y: data[0], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 1,
          barRods: [
            BarChartRodData(y: data[1], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 2,
          barRods: [
            BarChartRodData(y: data[2], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 3,
          barRods: [
            BarChartRodData(y: data[3], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 4,
          barRods: [
            BarChartRodData(y: data[4], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 5,
          barRods: [
            BarChartRodData(y: data[5], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
        BarChartGroupData(
          x: 6,
          barRods: [
            BarChartRodData(y: data[6], width: 12, colors: colorProfile)
          ],
          showingTooltipIndicators: [0],
        ),
      ];
}
