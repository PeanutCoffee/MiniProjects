import Foundation

enum Planet: String, CaseIterable {
  case mercury
  case venus
  case earth
  case mars
  case saturn

  var name: String {
    rawValue.prefix(1).capitalized + rawValue.dropFirst()
  }
}
