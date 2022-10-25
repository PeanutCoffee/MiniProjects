//
//  SceneVC.swift
//  Swift Collection
//
//  Created by Aarish on 18/08/22.
//

import Foundation
import SceneKit
class SceneVC: UIViewController {
    let scene  = SCNScene(named: "scenes.scnassets/Solar Scene.scn")!
    @IBOutlet weak var sceneView: SCNView!
    override func viewDidLoad() {
        sceneView.scene = scene
        sceneView.allowsCameraControl = true
        SceneVC.applyTextures(to: scene)
        animate(to: scene)
    }
    static func applyTextures(to scene: SCNScene?) {
      // 1
      for planet in Planet.allCases {
        // 2
        let identifier = planet.rawValue
        // 3
        let node = scene?.rootNode
          .childNode(withName: identifier, recursively: false)

          // Images courtesy of Solar System Scope https://bit.ly/3fAWUzi
          // 4
          let texture = UIImage(named: identifier)
          // 5
          node?.geometry?.firstMaterial?.diffuse.contents = texture
          let skyboxImages = (1...6).map { UIImage(named: "skybox\($0)") }
          // 2
          scene?.background.contents = skyboxImages
      }
    }
    func animate(to scene: SCNScene?) {
        for planet in Planet.allCases {
            let node = scene?.rootNode.childNode(withName: planet.rawValue, recursively: false)
            let moveUp = SCNAction.rotateBy(x: 0, y: 1, z: 0, duration: 5)
            moveUp.timingMode = .linear
            //        let moveDown = SCNAction.moveBy(x: 0, y: -1, z: 0, duration: 1)
            //        moveDown.timingMode = .easeInEaseOut;
            let moveSequence = SCNAction.sequence([moveUp])
            let moveLoop = SCNAction.repeatForever(moveSequence)
            node?.runAction(moveLoop)
        }
    }
}
